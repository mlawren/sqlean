// Copyright (c) 2024 Mark Lawrence, MIT License
// https://github.com/nalgeon/sqlean

#include "config.h"
#include "sqlean.h"
#if SQLEAN_MSYSTEM
#include <stdlib.h>
#endif
#include <string.h>
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT3

// Returns the current Sqlean version.
void sqlean_version(sqlite3_context* context, int argc, sqlite3_value** argv) {
    if (argc == 0) {
        sqlite3_result_text(context, SQLEAN_VERSION, -1, SQLITE_STATIC);
    } else if (argc == 1) {
        const char* token = (char*)sqlite3_value_text(argv[0]);
        if (strcmp(token,"HAVE_ARPA_INET_H") == 0) {
            sqlite3_result_int(context, HAVE_ARPA_INET_H);
        } else if (strcmp(token,"HAVE_TIMESPEC_GET") == 0) {
            sqlite3_result_int(context, HAVE_TIMESPEC_GET);
        } else if (strcmp(token,"SQLEAN_CRYPTO") == 0) {
            sqlite3_result_int(context, SQLEAN_CRYPTO);
        } else if (strcmp(token,"SQLEAN_DEFINE") == 0) {
            sqlite3_result_int(context, SQLEAN_DEFINE);
        } else if (strcmp(token,"SQLEAN_FILEIO") == 0) {
            sqlite3_result_int(context, SQLEAN_FILEIO);
        } else if (strcmp(token,"SQLEAN_FUZZY") == 0) {
            sqlite3_result_int(context, SQLEAN_FUZZY);
        } else if (strcmp(token,"SQLEAN_IPADDR") == 0) {
            sqlite3_result_int(context, SQLEAN_IPADDR);
        } else if (strcmp(token,"SQLEAN_MATH") == 0) {
            sqlite3_result_int(context, SQLEAN_MATH);
#if SQLEAN_MSYSTEM
        // For testing purposes under Gitbash only!
        // Does not work if SQLite called directly from Windows/CMD.
        } else if (strcmp(token,"SQLEAN_MSYSTEM") == 0) {
            const char *env_msystem = getenv("MSYSTEM");
            if (env_msystem != NULL) {
                if (strncmp(env_msystem, "MINGW", 5) == 0) {
                    sqlite3_result_int(context, 1);
                }
            } else {
                sqlite3_result_int(context, 0);
            }
#endif
        } else if (strcmp(token,"SQLEAN_REGEXP") == 0) {
            sqlite3_result_int(context, SQLEAN_REGEXP);
        } else if (strcmp(token,"SQLEAN_SQLEAN") == 0) {
            sqlite3_result_int(context, SQLEAN_SQLEAN);
        } else if (strcmp(token,"SQLEAN_STATS") == 0) {
            sqlite3_result_int(context, SQLEAN_STATS);
        } else if (strcmp(token,"SQLEAN_TEXT") == 0) {
            sqlite3_result_int(context, SQLEAN_TEXT);
        } else if (strcmp(token,"SQLEAN_TIME") == 0) {
            sqlite3_result_int(context, SQLEAN_TIME);
        } else if (strcmp(token,"SQLEAN_UNICODE") == 0) {
            sqlite3_result_int(context, SQLEAN_UNICODE);
        } else if (strcmp(token,"SQLEAN_UUID") == 0) {
            sqlite3_result_int(context, SQLEAN_UUID);
        } else if (strcmp(token,"SQLEAN_VSV") == 0) {
            sqlite3_result_int(context, SQLEAN_VSV);
        }
        else {
            sqlite3_result_null(context);
        }
    }
}

#if !HAVE_ARPA_INET_H || !HAVE_TIMESPEC_GET
void sqlean_unsupported(
    sqlite3_context* context, int argc, sqlite3_value** argv) {

    sqlite3_result_error(context, "use of unsupported sqlean function",-1);
}
#endif
