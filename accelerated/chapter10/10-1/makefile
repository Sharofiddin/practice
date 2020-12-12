CXX = g++
CC = g++
CXXFLAGS = -I. -I../../chapter08

all: main		

Student_info.o:	Student_info.cc Student_info.h

grade.o:	grade.cc ../../chapter08/median.h Student_info.h

main.o: main.cc grade.h ../../chapter08/median.h Student_info.h

main: main.o grade.o Student_info.o 

test:		all
	./main <../../data/grades
clobber:
	rm -f *.o *.exe main 
