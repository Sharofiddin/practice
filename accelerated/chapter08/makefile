CXX = g++
CC = g++
CXXFLAGS = -I. -I../chapter04 -I ../chapter06

all:		split_main main3 analysis

Student_info.o:	../chapter04/Student_info.cc ../chapter04/Student_info.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/Student_info.cc

split_main.o:	split_main.cc ../chapter05/split.h

split_main:	split_main.o

analysis.o:	../chapter06/analysis.cc ../chapter06/analysis.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/analysis.cc
8-1.o: 8-1.cc

8-1: grade.o Student_info.o analysis.o grade_check.o

8-2_test: 8-2_test.cc 8-2.h

grade.o:	../chapter06/grade.cc ../chapter06/grade.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/grade.cc

main3.o:	../chapter04/main3.cc ../chapter06/grade.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/main3.cc

main3:		main3.o grade.o analysis.o Student_info.o

analysis:	grade.o analysis.o Student_info.o grade_analysis.o grade_check.o


grade_analysis.o: ../chapter06/grade_analysis.cc ../chapter06/analysis.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/grade_analysis.cc

grade_check.o:	../chapter06/grade_check.cc
	$(CXX) $(CXXFLAGS) -c ../chapter06/grade_check.cc
stl_algs_test: stl_algs.h
test:		all
	./split_main <split_main.cc
	./main3 < ../data/single_grade
	./main3 < ../data/grades
	./analysis < ../data/grades
	./8-1 < ../data/grades
	./8-2
clobber:
	rm -f *.o *.exe core split_main main3 analysis 8-2_test stl_algs_test
