// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

#ifndef SQLEAN_H
#define SQLEAN_H

#include "config.h"
#include "sqlite3ext.h"

void sqlean_version(
    sqlite3_context* context,
    int argc,
    sqlite3_value** argv);

#if !HAVE_ARPA_INET_H || !HAVE_TIMESPEC_GET
void sqlean_unsupported(
    sqlite3_context* context,
    int argc,
    sqlite3_value** argv);
#endif

#endif /* SQLEAN_H */
