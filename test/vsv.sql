-- Copyright (c) 2021 Anton Zhiyanov, MIT License
-- https://github.com/nalgeon/sqlean

.shell bash -c "echo '11,Diane,London' > people.csv"
.shell bash -c "echo '22,Grace,Berlin' >> people.csv"
.shell bash -c "echo '33,Alice,Paris' >> people.csv"

create virtual table people using vsv(
    filename=people.csv,
    schema="create table people(id integer, name text, city text)",
    columns=3,
    affinity=integer
);
select '01', count(*) = 3 from people;
select '02', (id, name, city) = (22, 'Grace', 'Berlin') from people where id = 22;
select '03', typeof(id) = 'integer' from people where id = 22;

.shell bash -c 'rm -f people.csv'
