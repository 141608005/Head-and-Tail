try : head.o tail.o
head:
	gcc -Wall -o head head.c
tail:
	gcc -Wall -o tail tail.c
