// Copyright (c) 2024 Mark Lawrence, GPL3
// https://github.com/mlawren/sqlean

// Test Anything Protocol functions for SQLite

#include <assert.h>
#include <stdio.h>
#include <string.h>


#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT3

typedef struct {
    unsigned int test_count;
    unsigned int fails;
} TapUserData;

#define TNAME 2
#define GOT 1
#define WANT 0

static void tap_is(sqlite3_context* context, int argc, sqlite3_value** argv) {
    assert(argc == 3);
    static const char *azType[] = { "integer", "real", "text", "blob", "null" };
    static const char *okType[] = { "not ok", "ok" };

	TapUserData *data = (TapUserData *)sqlite3_user_data(context);

    if (data) {
        data->test_count++;
    } else {
        sqlite3_result_error(context, "TapUserData not found", -1);
		return;
    }

    unsigned int got_type = sqlite3_value_type(argv[GOT]);
    unsigned int want_type = sqlite3_value_type(argv[WANT]);
    unsigned int tname_type = sqlite3_value_type(argv[TNAME]);

    if (tname_type == SQLITE_NULL) {
        sqlite3_result_error(context,
            "usage: tap_is(got, expected, TESTNAME)", -1);
		return;
    }

	const char* test_name = (const char*)sqlite3_value_text(argv[TNAME]);
    char* error_msg = "";

    unsigned int ok = 0;
    if (got_type != want_type) {
        error_msg = sqlite3_mprintf("\n"
            "^TAP # Failed test %u '%s'\n"
            "^TAP #      got type: %s\n"
            "^TAP # expected type: %s\n"
            "^TAP #",
            data->test_count, test_name,
            azType[got_type - 1], azType[want_type - 1]);
        goto end;
    }

    const char* got_value = (const char*)sqlite3_value_text(argv[GOT]);
    const char* want_value = (const char*)sqlite3_value_text(argv[WANT]);

    if (strcmp(got_value, want_value) != 0) {
        error_msg = sqlite3_mprintf( "\n"
            "^TAP # Failed test %u '%s'\n"
            "^TAP #      got: %s\n"
            "^TAP # expected: %s\n"
            "^TAP #",
            data->test_count, test_name,
            got_value, want_value);
    }
    else {
        ok = 1;
    }

end:
    char* result = sqlite3_mprintf( "^TAP %s %u - %s%s", okType[ok],
        data->test_count, test_name, error_msg);
    sqlite3_result_text(context, result, -1, sqlite3_free);
    if (ok != 1) {
        data->fails++;
        sqlite3_free(error_msg);
    }
}

static void tap_done(sqlite3_context* context, int argc, sqlite3_value** argv) {
    assert(argc == 0);

	TapUserData *data = (TapUserData *)sqlite3_user_data(context);
    if (!data) {
        sqlite3_result_error(context, "TapUserData not found", -1);
		return;
    }

    char* result = sqlite3_mprintf( "1..%u", data->test_count);
    sqlite3_result_text(context, result, -1, sqlite3_free);
    data->test_count = 0;
    data->fails = 0;
}

int tap_init(sqlite3* db, char **pzErrMsg, const sqlite3_api_routines *pApi) {
    static const int flags =
        SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC;

    TapUserData *data = (TapUserData *)sqlite3_malloc(sizeof(TapUserData));
    if (!data) {
        *pzErrMsg = "Failed to allocate memory for user data.";
        return SQLITE_ERROR;
    }
    data->test_count = 0;
    data->fails = 0;

    int rc = sqlite3_create_function(db, "tap_is", 3,flags, data,
        tap_is, NULL, NULL);
    if (rc != SQLITE_OK) {
        sqlite3_free(data);
        *pzErrMsg = sqlite3_mprintf("Failed to create function: %s",
            sqlite3_errmsg(db));
        return rc;
    }

    rc = sqlite3_create_function(db, "tap_done", 0,flags, data,
        tap_done, NULL, NULL);
    if (rc != SQLITE_OK) {
        sqlite3_free(data);
        *pzErrMsg = sqlite3_mprintf("Failed to create function: %s",
            sqlite3_errmsg(db));
        return rc;
    }

    return SQLITE_OK;
}
