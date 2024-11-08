// Copyright (c) 2024 Mark Lawrence, MIT License
// https://github.com/nalgeon/sqlean

#include <string.h>
#include "sqlean.h"
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT3

// Returns the current Sqlean version.
void sqlean_version(sqlite3_context* context, int argc, sqlite3_value** argv) {
    if (argc == 0) {
        sqlite3_result_text(context, SQLEAN_VERSION, -1, SQLITE_STATIC);
    } else if (argc == 1) {
        const char* token = (char*)sqlite3_value_text(argv[0]);
        if (strcmp(token,"HAVE_TIMESPEC_GET") == 0) {
#ifdef HAVE_TIMESPEC_GET
            sqlite3_result_int(context, 1);
#else
            sqlite3_result_int(context, 0);
#endif
        }
        else {
            sqlite3_result_null(context);
        }
    }
}

void sqlean_unimplemented(
    sqlite3_context* context, int argc, sqlite3_value** argv) {

    sqlite3_result_error(context, "Use of unimplemented sqlean function",-1);
}

