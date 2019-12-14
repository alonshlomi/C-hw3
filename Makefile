CC = gcc
FLAGS = -g -Wall

all: isort isort.o main.o txtfind maint.o txtfind.o

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

isort: main.o isort.o
	$(CC) $(FLAGS) main.o isort.o -o isort

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

maint.o: maint.c txtfind.h
	$(CC) $(FLAGS) -c maint.c

txtfind: maint.o txtfind.o
	$(CC) $(FLAGS) maint.o txtfind.o -o txtfind

.PHONY: clean all

clean:
	rm -f *.o isort txtfind