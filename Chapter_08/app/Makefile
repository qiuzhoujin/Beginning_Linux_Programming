src=select4
INCDIR=/usr/include/mysql
LIBDIR=/usr/lib/mysql
LIB=mysqlclient
tar=a.out
C:
	gcc -g -o $(tar) -I$(INCDIR) app_mysql.c app_test.c -L$(LIBDIR) -l$(LIB)
	./$(tar)
