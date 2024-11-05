-- Copyright (c) 2023 Anton Zhiyanov, MIT License
-- https://github.com/nalgeon/sqlean

select '100_01', sqlean_version() is not null;
select '100_02', sqlean_version('SQLEAN_SQLEAN') is 1;
select '100_03', sqlean_version('SQLEAN_NOTEXIST') is NULL;
