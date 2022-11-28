EXEC = PJ3
CC = g++
CFLAGS = -c -Wall
#
$(EXEC)	:main.o util.o minheap.o stack.o
	$(CC) -o $(EXEC) main.o util.o minheap.o stack.o
#
main.o	:main.cpp util.h minheap.h
	$(CC) $(CFLAGS) main.cpp
#
util.o	:util.cpp util.h
	$(CC) $(CFLAGS) util.cpp
#
minheap.o	:minheap.cpp minheap.h
	$(CC) $(CFLAGS) minheap.cpp
#
stack.o	:stack.cpp stack.h
	$(CC) $(CFLAGS) stack.cpp
	
clean:
	$(RM) main.o util.o minheap.o PJ3

