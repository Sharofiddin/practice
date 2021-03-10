CC = g++
CXX = g++

Str.o: Str.cc Str.h
main.o:	Str.o main.cc Str.h
main:	Str.h main.o Str.o
pics.o:		pics.cc pics.h
pics_main.o:	pics_main.cc pics.h
pics_main:	pics_main.o pics.o Str.o

split.o:	split.cc split.h Str.h

split_main.o:	split_main.cc split.h Str.h

split_main2.o:	split_main2.cc split.h Str.h

split_main:	split_main.o split.o Str.o

split_main2:	split_main2.o split.o Str.o
all: main
test: all
	./main
clobber:
	rm -rf *.o main
