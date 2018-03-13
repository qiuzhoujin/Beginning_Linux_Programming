SRC=hello
TAR=$(SRC)
foo:
	gcc -o $(TAR) $(SRC).c
	./$(TAR)

C1:
	gcc -c bill.c fred.c
	ls *.o

C2:
	gcc -c program.c
	gcc -o program program.o bill.o
	./program

ar:
	ar crv libfoo.a bill.o fred.o
	ranlib libfoo.a

C3:
	gcc -o program program.o libfoo.a
	./program

C4:
	gcc -o program program.o -L. -lfoo
	./program
