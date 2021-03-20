CXX = g++
CC = g++
CXXFLAGS = -I. -I../chapter08

all:		main_core main_grad main_orig main_core_ptrs
exercises:  13-1 13-2 13-3 13-4 13-5 13-6 13-7 13-8

Core.o:	Core.cc Core.h

Grad.o:	Grad.cc Core.h
13-1.o: 13-1.cc Core.h
13-2.o: 13-2.cc Core.h 
13-1: 13-1.o grade.o  read_hw.o Core.o
13-2: 13-2.o grade.o  read_hw.o Core.o

13-3.o: 13-3.cc Core.h 
13-3: 13-3.o grade.o  read_hw.o Core.o

13-4.o: 13-4.cc Core.h 
13-4: 13-4.o grade.o  read_hw.o Core.o

13-5.o: 13-5.cc Core.h 
13-5: 13-5.o grade.o  read_hw.o Core.o

13-6.o: 13-6.cc Core.h 
13-6: 13-6.o grade.o  read_hw.o Core.o

13-7.o: 13-7.cc Core.h 
13-7: 13-7.o grade.o  read_hw.o Core.o

13-8.o: 13-8.cc Core.h Student_info.h
13-8: 13-8.o grade.o  read_hw.o Core.o Student_info.o

Student_info.o:	Student_info.cc ../chapter08/median.h Student_info.h Core.h

grade.o:	grade.cc ../chapter08/median.h Student_info.h

read_hw.o:	read_hw.cc ../chapter08/median.h Student_info.h

main_core.o:	main_core.cc Core.h ../chapter08/median.h

main_grad.o:	main_grad.cc Core.h ../chapter08/median.h

main_orig.o:	main_orig.cc Core.h ../chapter08/median.h Student_info.h

main_core_ptrs.o:	main_core_ptrs.cc Core.h ../chapter08/median.h

main_orig:	main_orig.o grade.o Student_info.o read_hw.o Core.o

main_core:	main_core.o grade.o  read_hw.o Core.o

main_grad:	main_grad.o grade.o  read_hw.o Core.o

main_core_ptrs:	main_core_ptrs.o grade.o  read_hw.o Core.o

test:		all
	./main_core <../data/grades_core
	./main_grad <../data/grades_grad
	./main_orig <../data/mixed_grades
	./main_core_ptrs <../data/mixed_grades

clobber:
	rm -f *.o *.exe core main_core main_grad main_orig main_core_ptrs \
		13-1 13-2 13-3 13-4 13-5 13-6 13-7 13-8
