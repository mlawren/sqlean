// Copyright (c) 2021 Vincent Bernat, MIT License
// https://github.com/nalgeon/sqlean

// IP address manipulation in SQLite.

#ifndef TAP_EXTENSION_H
#define TAP_EXTENSION_H

#include "sqlite3ext.h"

int tap_init(sqlite3* db);

#endif /* TAP_EXTENSION_H */
