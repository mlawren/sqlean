// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

// Universally Unique IDentifiers (UUIDs) in SQLite

#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

#include "sqlean.h"
#include "uuid/extension.h"

#ifdef _WIN32
__declspec(dllexport)
#endif
    int sqlite3_uuid_init(sqlite3* db, char** errmsg_ptr, const sqlite3_api_routines* api) {
    (void)errmsg_ptr;
    SQLITE_EXTENSION_INIT2(api);
    static const int flags = SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC;
    sqlite3_create_function(db, "sqlean_version", 0, flags, 0, sqlean_version, 0, 0);
    return uuid_init(db);
}
