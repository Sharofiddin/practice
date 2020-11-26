CXX = g++
CC = g++
CXXFLAGS = -I. -I../chapter08

all:		grading_prog 9-4 9-3

Student_info.o:	Student_info.cc Student_info.h

grade.o:	grade.cc ../chapter08/median.h Student_info.h

grading_prog.o:	grading_prog.cc grade.h ../chapter08/median.h Student_info.h

grading_prog:	grading_prog.o grade.o Student_info.o

9-3.o:	9-3.cc grade.h ../chapter08/median.h Student_info.h

9-3: 9-3.o grade.o Student_info.o 

9-4.o:	9-4.cc grade.h ../chapter08/median.h Student_info.h

9-4: 9-4.o grade.o Student_info.o 

test:		all
	./grading_prog <../data/grades
	./9-4 <../data/grades
	./9-3 <../data/grades
clobber:
	rm -f *.o *.exe 9-4 9-3 core grading_prog
