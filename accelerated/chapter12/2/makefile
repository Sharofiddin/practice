CC = g++
CXX = g++

Str.o: Str.cc Str.h
main.o:	Str.o main.cc Str.h
main:	Str.h main.o Str.o
all: main
test: all
	./main
clobber:
	rm -rf *.o main
