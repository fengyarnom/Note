# SQLite Tutorial

In this document,i will write down the  syntax of sqlite so that i can review it later.



### Create a database

We can use `sqlite` command to create a new SQLite database and `.open ` command is used to open an existing database.

```sqlite
sqlite DatabaseName.db
or
.open DatabaseName.db
```



### Dump the database

We can use `.dump` dot command to export complete database in a text file using the following SQLite command at the command prompt.

```
sqlite3 testDB.db .dump > testDB.sql
```

The above command will convert the entire contents of **testDB.db** database into SQLite statements and dump it into ASCII text file **testDB.sql**. You can perform restoration from the generated testDB.sql in a simple way as follows −

```
sqlite3 testDB.db < testDB.sql
```



### Create a table

We can use `CREATE TABLE` statement to create a new table in database

```
CREATE TABLE database_name.table_name(
   column1 datatype PRIMARY KEY(one or more columns),
   column2 datatype,
   column3 datatype,
   .....
   columnN datatype
);
```

`CREATE TABLE` is the keyword telling the database system to create a new table. The unique name or identifier for the table follows the CREATE TABLE statement. Optionally, **you can specify *database_name* along with *table_name*.**

#### Example：

```
sqlite> CREATE TABLE COMPANY(
   ID INT PRIMARY KEY     NOT NULL,
   NAME           TEXT    NOT NULL,
   AGE            INT     NOT NULL,
   ADDRESS        CHAR(50),
   SALARY         REAL
);
```

#### .table

This command can list down all the table in database(if i have other attached database，it also can list down)

```
sqlite>.tables
COMPANY
```

#### .schema

This command can show complete information about a specific table.

```
sqlite>.schema COMPANY
CREATE TABLE COMPANY(
   ID INT PRIMARY KEY     NOT NULL,
   NAME           TEXT    NOT NULL,
   AGE            INT     NOT NULL,
   ADDRESS        CHAR(50),
   SALARY         REAL
);
```



### DROP a table

We can use `DROP TBALE` statement to remove a specific table.

```
DROP TABLE database_name.table_name;
```



#### INSERT QUERY

We can use `INSERT INTO` statement to add new rows of data into a table in database.

```
INSERT INTO TABLE_NAME [(column1, column2, column3,...columnN)]  
VALUES (value1, value2, value3,...valueN);
```

Here, column1, column2,...columnN are the names of the columns in the table into which you want to insert data.

You may not need to specify the column(s) name in the SQLite query if you are adding values for all the columns of the table. HoWever, make sure the order of the values is in the same order as the columns in the table. The SQLite INSERT INTO syntax would be as follows −

```
INSERT INTO TABLE_NAME VALUES (value1,value2,value3,...valueN);
```

```
INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
VALUES (1, 'Paul', 32, 'California', 20000.00 );
```



### SELECT QUERY

We can use `SELECT QUERY` statement to fetch the data form a SQLite database table which returns data in the form of a result table.These result tables are also called **result sets**.

```
SELECT column1, column2, columnN FROM table_name;
```

Here, column1, column2 ... are the fields of a table, whose values you want to fetch. If you want to fetch all the fields available in the field, then you can use the following syntax −

```
SELECT * FROM table_name;
```

Following is an example to fetch and display all these records using SELECT statement. Here, the first three commands have been used to set a properly formatted output.

```
sqlite>.header on
sqlite>.mode column
sqlite> SELECT * FROM COMPANY;
```



### WHERE Clause

SQLite **WHERE** clause is used to specify a condition while fetching the data from one table or multiple tables.

If the given condition is satisfied, means true, then it returns the specific value from the table. You will have to use WHERE clause to filter the records and fetching only necessary records.

The WHERE clause not only is used in SELECT statement, but it is also used in UPDATE, DELETE statement, etc., which will be covered in subsequent chapters.

```sqlite
SELECT column1, column2, columnN 
FROM table_name
WHERE [condition]
```

You can specify a condition using Comparision or Logical Operators such as >, <, =, LIKE, NOT, etc. Consider COMPANY table with the following records −

```sqlite
ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
2           Allen       25          Texas       15000.0
3           Teddy       23          Norway      20000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
6           Kim         22          South-Hall  45000.0
7           James       24          Houston     10000.0
```

Following is a simple examples showing the usage of SQLite Logical Operators. Following SELECT statement lists down all the records where AGE is greater than or equal to 25 **AND** salary is greater than or equal to 65000.00.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE AGE >= 25 AND SALARY >= 65000;

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
```

Following SELECT statement lists down all the records where AGE is greater than or equal to 25 **OR** salary is greater than or equal to 65000.00.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE AGE >= 25 OR SALARY >= 65000;

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
2           Allen       25          Texas       15000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
```

Following SELECT statement lists down all the records where AGE is not NULL, which means all the records because none of the record has AGE equal to NULL.

```sqlite
sqlite>  SELECT * FROM COMPANY WHERE AGE IS NOT NULL;

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
2           Allen       25          Texas       15000.0
3           Teddy       23          Norway      20000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
6           Kim         22          South-Hall  45000.0
7           James       24          Houston     10000.0
```

Following SELECT statement lists down all the records where NAME starts with 'Ki', does not matter what comes after 'Ki'.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE NAME LIKE 'Ki%';

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
6           Kim         22          South-Hall  45000.0
```

Following SELECT statement lists down all the records where NAME starts with 'Ki', does not matter what comes after 'Ki'.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE NAME GLOB 'Ki*';

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
6           Kim         22          South-Hall  45000.0
```

Following SELECT statement lists down all the records where AGE value is either 25 or 27.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE AGE IN ( 25, 27 );

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
2           Allen       25          Texas       15000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
```

Following SELECT statement lists down all the records where AGE value is neither 25 nor 27.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE AGE NOT IN ( 25, 27 );

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
3           Teddy       23          Norway      20000.0
6           Kim         22          South-Hall  45000.0
7           James       24          Houston     10000.0
```

Following SELECT statement lists down all the records where AGE value is in BETWEEN 25 AND 27.

```sqlite
sqlite> SELECT * FROM COMPANY WHERE AGE BETWEEN 25 AND 27;

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
2           Allen       25          Texas       15000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
```

Following SELECT statement makes use of SQL sub-query, where sub-query finds all the records with AGE field having SALARY > 65000 and later WHERE clause is being used along with EXISTS operator to list down all the records where AGE from the outside query exists in the result returned by the sub-query −

```sqlite
sqlite> SELECT AGE FROM COMPANY 
   WHERE EXISTS (SELECT AGE FROM COMPANY WHERE SALARY > 65000);

AGE
----------
32
25
23
25
27
22
24
```

Following SELECT Query makes use of SQL sub-query where sub-query finds all the records with AGE field having SALARY > 65000 and later WHERE clause is being used along with > operator to list down all the records where AGE from the outside query is greater than the age in the result returned by the sub-query.

```sqlite
sqlite> SELECT * FROM COMPANY 
   WHERE AGE > (SELECT AGE FROM COMPANY WHERE SALARY > 65000);

ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
```



### UPDATE QUERY

We can use `UPDATE` Query to modify the existing records in a table.We also can use `clause` with UPDATE query ti updata selectd rows,**otherwise all the rows would be updatae**

```
UPDATE table_name
SET column1 = value1, column2 = value2...., columnN = valueN
WHERE [condition];
```

```
sqlite> UPDATE COMPANY SET ADDRESS = 'Texas' WHERE ID = 6;
```



### DELETE Query

We can use `DELETE` Query to delete the existing records from a table. You can use `WHERE` clause with DELECT query to delete the selected rows,otherwise all the records would be deleted

```
DELETE FROM table_name
WHERE [condition];
```

```
sqlite> DELETE FROM COMPANY WHERE ID = 7;
```

If you want to DELETE all the records from COMPANY table, you do not need to use WHERE clause with DELETE query, which will be as follows −

```
sqlite> DELETE FROM COMPANY;
```

