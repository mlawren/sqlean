// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

// SQLite extension for working with regular expressions.

#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

#include "regexp/extension.h"
#include "sqlean.h"

#ifdef _WIN32
__declspec(dllexport)
#endif
    int sqlite3_regexp_init(sqlite3* db, char** errmsg_ptr, const sqlite3_api_routines* api) {
    (void)errmsg_ptr;
    SQLITE_EXTENSION_INIT2(api);
    static const int flags = SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC;
    sqlite3_create_function(db, "sqlean_version", 0, flags, 0, sqlean_version, 0, 0);
    return regexp_init(db);
}
