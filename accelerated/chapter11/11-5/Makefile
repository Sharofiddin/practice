CXX = g++ -Wall
CC = g++ -Wall
CXXFLAGS = -I. -I../../chapter08

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: main

grade.o: grade.cc ../../chapter08/median.h grade.h 
Student_info.o:	Student_info.cc ../../chapter08/median.h grade.h
main.o: main.cc Student_info.h ../../chapter08/median.h grade.h
main: main.o Student_info.o grade.o 

clobber: 
	rm -rf *.o test Student_info main
test: main
	./main <../../data/grades_my
