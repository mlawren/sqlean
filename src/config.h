// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

#ifndef CONFIG_H
#define CONFIG_H

#include "_config.h"

#ifndef HAVE_ARPA_INET_H
#define HAVE_ARPA_INET_H 0
#endif

#ifndef HAVE_WS2TCPIP_H
#define HAVE_WS2TCPIP_H 0
#endif

#ifndef HAVE_TIMESPEC_GET
#define HAVE_TIMESPEC_GET 0
#endif

#ifndef SQLEAN_CRYPTO
#define SQLEAN_CRYPTO 0
#endif

#ifndef SQLEAN_DEFINE
#define SQLEAN_DEFINE 0
#endif

#ifndef SQLEAN_FILEIO
#define SQLEAN_FILEIO 0
#endif

#ifndef SQLEAN_FUZZY
#define SQLEAN_FUZZY 0
#endif

#ifndef SQLEAN_IPADDR
#define SQLEAN_IPADDR 0
#endif

#ifndef SQLEAN_MATH
#define SQLEAN_MATH 0
#endif

#ifndef SQLEAN_MSYSTEM
#define SQLEAN_MSYSTEM 0
#endif

#ifndef SQLEAN_REGEXP
#define SQLEAN_REGEXP 0
#endif

#ifndef SQLEAN_SQLEAN
#define SQLEAN_SQLEAN 0
#endif

#ifndef SQLEAN_STATS
#define SQLEAN_STATS 0
#endif

#ifndef SQLEAN_TEXT
#define SQLEAN_TEXT 0
#endif

#ifndef SQLEAN_TIME
#define SQLEAN_TIME 0
#endif

#ifndef SQLEAN_UNICODE
#define SQLEAN_UNICODE 0
#endif

#ifndef SQLEAN_UUID
#define SQLEAN_UUID 0
#endif

#ifndef SQLEAN_VSV
#define SQLEAN_VSV 0
#endif

#endif /* CONFIG_H */
