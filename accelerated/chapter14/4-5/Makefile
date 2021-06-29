CXX = g++
CC = g++
CXXFLAGS = -I. -I../
Vec.o:
	$(CC) $(CXXFLAGS) -c ../Vec_clone.cc -o Vec.o
Str.o: Vec.o
	$(CC) $(CXXFLAGS) -c ../Str.cc -o Str.o
pics.o:	pics.cc pics.h
pics_main.o:	pics_main.cc pics.h	../Str.h ../Ptr.h ../Vec.h
pics_main:	pics_main.o pics.o Vec.o Str.o 
split.o:	split.cc split.h
split_main.o:	split_main.cc 
split_main:	Vec.o Str.o split.o
clobber:
	rm -rf *.o split_main pics_main