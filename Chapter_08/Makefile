src=update1
INCDIR=/usr/include/mysql
LIBDIR=/usr/lib/mysql
LIB=mysqlclient
tar=a.out
C:
	gcc -g -o $(tar) -I$(INCDIR) $(src).c -L$(LIBDIR) -l$(LIB)
	./$(tar)
