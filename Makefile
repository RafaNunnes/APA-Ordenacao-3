main:	main.o	ord.o
	gcc main.o ord.o -o main
	./main

main.o:	main.c
	gcc -c main.c

ord.o:	ord.c	ord.h
	gcc -c ord.c

clean:
	rm *.o
