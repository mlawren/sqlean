// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

// Sqlean extensions bundle.

#include "config.h"
#include "sqlean.h"
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

#if SQLEAN_CRYPTO
#include "crypto/extension.h"
#endif

#if SQLEAN_DEFINE
#include "define/extension.h"
#endif

#if SQLEAN_FILEIO
#include "fileio/extension.h"
#endif

#if SQLEAN_FUZZY
#include "fuzzy/extension.h"
#endif

#if SQLEAN_IPADDR
#include "ipaddr/extension.h"
#endif

#if SQLEAN_MATH
#include "math/extension.h"
#endif

#if SQLEAN_REGEXP
#include "regexp/extension.h"
#endif

#if SQLEAN_STATS
#include "stats/extension.h"
#endif

#if SQLEAN_TEXT
#include "text/extension.h"
#endif

#if SQLEAN_TIME
#include "time/extension.h"
#endif

#if SQLEAN_UNICODE
#include "unicode/extension.h"
#endif

#if SQLEAN_UUID
#include "uuid/extension.h"
#endif

#if SQLEAN_VSV
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


#if SQLEAN_CRYPTO
    crypto_init(db);
#endif

#if SQLEAN_DEFINE
    define_init(db);
#endif

#if SQLEAN_FILEIO
    fileio_init(db);
#endif

#if SQLEAN_FUZZY
    fuzzy_init(db);
#endif

#if SQLEAN_IPADDR
    ipaddr_init(db);
#endif

#if SQLEAN_MATH
    math_init(db);
#endif

#if SQLEAN_REGEXP
    regexp_init(db);
#endif

#if SQLEAN_STATS
    stats_init(db);
#endif

#if SQLEAN_TEXT
    text_init(db);
#endif

#if SQLEAN_TIME
    time_init(db);
#endif

#if SQLEAN_UNICODE
    unicode_init(db);
#endif

#if SQLEAN_UUID
    uuid_init(db);
#endif

#if SQLEAN_VSV
    vsv_init(db);
#endif

    return SQLITE_OK;
}
