drop table if exists account_type
drop table if exists account
drop table if exists expense_type
drop table if exists expense
create table account_type(id integer, name varchar(40) not NULL, color varchar(40), icon varchar(40), primary key(id))
create table account(id integer, name varchar(40) not NULL, account_type_id integer not NULL, initial_balance integer default 0, balance_limit integer default 0, primary key(id))
create table expense_type(id integer, name varchar(40) not NULL, color varchar(40), icon varchar(40), importance integer default 1, primary key(id))
create table expense(id integer, name varchar(40) not NULL, expense_type_id integer not NULL, account_id integer not NULL, date varchar(40), value integer default 0, comment varchar(100), primary key(id))
insert into account_type (name, color, icon) values('Debit Card', '#7777FF', 'debit-card.svg')
insert into account_type (name, color, icon) values('Credit Card', '#FF4444', 'credit-card.svg')
insert into account_type (name, color, icon) values('Saving', '#44FF44', 'piggy-bank.svg')
insert into account_type (name, color, icon) values('Loan', '#FFFF44', 'house.svg')
insert into account_type (name, color, icon) values('Cash', '#00FF00', 'cash.svg')
insert into expense_type (name, color) values('Grocery', '#00FF00')
insert into expense_type (name, color) values('Household', '#00FFFF')
insert into expense_type (name, color) values('Car', '#00FF99')
insert into expense_type (name, color) values('Utilities', '#66FF22')
insert into account (name, account_type_id) values ('Temp', 1)
insert into expense (name, expense_type_id, account_id) values('Temp', '1', '1')
