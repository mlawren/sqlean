// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

// Sqlean extensions bundle.

#include "sqlean.h"
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

#ifdef SQLEAN_CRYPTO
#include "crypto/extension.h"
#endif

#ifdef SQLEAN_DEFINE
#include "define/extension.h"
#endif

#ifdef SQLEAN_FILEIO
#include "fileio/extension.h"
#endif

#ifdef SQLEAN_FUZZY
#include "fuzzy/extension.h"
#endif

// was #if !defined(_WIN32)
#ifdef SQLEAN_IPADDR
#include "ipaddr/extension.h"
#endif

#ifdef SQLEAN_MATH
#include "math/extension.h"
#endif

#ifdef SQLEAN_REGEXP
#include "regexp/extension.h"
#endif

#ifdef SQLEAN_STATS
#include "stats/extension.h"
#endif

#ifdef SQLEAN_TEXT
#include "text/extension.h"
#endif

#ifdef SQLEAN_TIME
#include "time/extension.h"
#endif

#ifdef SQLEAN_UNICODE
#include "unicode/extension.h"
#endif

#ifdef SQLEAN_UUID
#include "uuid/extension.h"
#endif

#ifdef SQLEAN_VSV
#include "vsv/extension.h"
#endif

#ifdef _WIN32
__declspec(dllexport)
#endif
    int sqlite3_sqlean_init(sqlite3* db, char** errmsg_ptr, const sqlite3_api_routines* api) {
    (void)errmsg_ptr;
    SQLITE_EXTENSION_INIT2(api);
    static const int flags = SQLITE_UTF8 | SQLITE_INNOCUOUS | SQLITE_DETERMINISTIC;
    sqlite3_create_function(db, "sqlean_version", 0, flags, 0, sqlean_version, 0, 0);
    sqlite3_create_function(db, "sqlean_version", 1, flags, 0, sqlean_version, 0, 0);

#ifdef SQLEAN_CRYPTO
    crypto_init(db);
#endif

#ifdef SQLEAN_DEFINE
    define_init(db);
#endif

#ifdef SQLEAN_FILEIO
    fileio_init(db);
#endif

#ifdef SQLEAN_FUZZY
    fuzzy_init(db);
#endif

// was #if !defined(_WIN32)
#ifdef SQLEAN_IPADDR
    ipaddr_init(db);
#endif

#ifdef SQLEAN_MATH
    math_init(db);
#endif

#ifdef SQLEAN_REGEXP
    regexp_init(db);
#endif

#ifdef SQLEAN_STATS
    stats_init(db);
#endif

#ifdef SQLEAN_TEXT
    text_init(db);
#endif

// was #if !defined(_WIN32) || defined(_WIN64)
#ifdef SQLEAN_TIME
    time_init(db);
#endif

#ifdef SQLEAN_UNICODE
    unicode_init(db);
#endif

#ifdef SQLEAN_UUID
    uuid_init(db);
#endif

#ifdef SQLEAN_VSV
    vsv_init(db);
#endif

    return SQLITE_OK;
}
