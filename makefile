CC=gcc
AR=ar
OBJECT_SORT=isort.o
OBJECT_LIBSORT=my_sort.o
FLAGS= -Wall -g

all: isort  

i: $(OBJECT_MAIN) 
	$(CC) $(FLAGS) -o isort $(OBJECT_MAIN) -lm 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

.PHONY: clean all

clean:
	rm -f *.o *.a connections