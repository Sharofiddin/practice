CXX = g++
CC = g++
Student_info.o:	Student_info.cc Student_info.h
main.o: main.cc Student_info.o
main: main.o Student_info.o
clobber: 
	rm -rf *.o main Student_info
test: main
	./main <data