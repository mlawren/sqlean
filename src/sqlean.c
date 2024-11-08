// Copyright (c) 2024 Mark Lawrence, MIT License
// https://github.com/nalgeon/sqlean

#include <string.h>
#include "config.h"
#include "sqlean.h"
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT3

// Returns the current Sqlean version.
void sqlean_version(sqlite3_context* context, int argc, sqlite3_value** argv) {
    sqlite3_result_text(context, SQLEAN_VERSION, -1, SQLITE_STATIC);
}

