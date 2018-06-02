CC = g++
FLAGS = -Wall -g -o
MAIN = main.cpp
IMP = imp.cpp
HEAD = prog5.h

app: main.o imp.o
	$(CC) $(FLAGS) app main.o imp.o

main.o: main.cpp
	$(CC) -c $(MAIN)

imp.o: imp.cpp
	$(CC) -c $(IMP)

.PHONY: clean
clean:	#clean the directory
	$(info -- cleaning the directory --)
	rm -f *.o app

.PHONY:	open
open:	#open files for editing
	$(info -- opening files --)
	vim -O $(MAIN) $(IMP) $(HEAD)
