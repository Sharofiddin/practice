CC = g++
CXX = g++

pics.o:	pics.cc pics.h ../Vec.h
pics_main.o:	pics_main.cc pics.h
pics_main: pics_main.o pics.o
test: pics_main
	./pics_main
clobber:
	rm -rf *.o pics_main