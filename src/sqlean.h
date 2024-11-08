// Copyright (c) 2023 Anton Zhiyanov, MIT License
// https://github.com/nalgeon/sqlean

#ifndef SQLEAN_H
#define SQLEAN_H

#ifndef SQLEAN_VERSION
#define SQLEAN_VERSION "main"
#endif
#include "sqlite3ext.h"

void sqlean_version(
    sqlite3_context* context,
    int argc,
    sqlite3_value** argv);

#endif /* SQLEAN_H */
