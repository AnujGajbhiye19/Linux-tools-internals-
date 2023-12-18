$(CC)=gcc

one: 1.o 2.o 3.o
	$(CC) 1.o 2.o 3.o -o out

1.o: 1.c	file.h
	$(CC) -c 1.c

2.o: 2.c	file.h
	$(CC) -c 2.c

3.o: 3.c	file.h
	$(CC) -c 3.c

clean:
	rm -rf *.o out
