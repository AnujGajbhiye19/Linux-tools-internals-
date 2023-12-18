$(CC)=$(gcc)


all: ex1.o ex2.o ex3.o
	$(CC) ex1.o ex2.o ex3.o -o out

ex1.o: ex1.c file.h
	$(CC) -c ex1.c 

ex2.o: ex2.c file.h
	$(CC) -c ex2.c 

ex3.o: ex3.c file.h
	$(CC) -c ex3.c 

clean:
	rm -rf *.o out

