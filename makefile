CC=gcc
AR=ar
OBJECT_SORT=isort.o
OBJECT_FIND=txtfind.o
FLAGS= -Wall -g

all: isort txtfind

isort: $(OBJECT_SORT) 
	$(CC) $(FLAGS) -o isort $(OBJECT_SORT) -lm 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind: $(OBJECT_FIND) 
	$(CC) $(FLAGS) -o txtfind $(OBJECT_FIND) -lm 

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o *.a isort txtfind