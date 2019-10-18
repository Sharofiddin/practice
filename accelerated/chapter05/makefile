CXX = g++
CC = g++

CXXFLAGS = -I../chapter04

all:		fails_vec1 fails_vec2 fails_iters fails_list fails_vec_5_6\
		split_main split_main2 pics_main

median.o:	../chapter04/median.cc ../chapter04/median.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/median.cc

Student_info.o:	../chapter04/Student_info.cc ../chapter04/Student_info.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/Student_info.cc

grade.o:	grade.cc grade.h

ext_main.o:	ext_main.cc grade.h ../chapter04/Student_info.h

list_main.o:	list_main.cc grade.h ../chapter04/Student_info.h

fails_vec1.o:	fails_vec1.cc grade.h ../chapter04/Student_info.h

fails_vec2.o:	fails_vec2.cc grade.h ../chapter04/Student_info.h

fails_iters.o:	fails_iters.cc grade.h ../chapter04/Student_info.h

fails_list.o:	fails_list.cc grade.h  ../chapter04/Student_info.h

fails_vec_5_6.o: fails_vec_5_6.cc grade.h ../chapter04/Student_info.h

fails_vec1:	fails_vec1.o ext_main.o grade.o median.o Student_info.o

fails_vec2:	fails_vec2.o ext_main.o grade.o median.o Student_info.o

fails_iters:	fails_iters.o ext_main.o grade.o median.o Student_info.o

fails_list:	fails_list.o list_main.o grade.o median.o Student_info.o

fails_vec_5_6:  fails_vec_5_6.o ext_main.o grade.o median.o Student_info.o

pics.o:		pics.cc pics.h

5_8.o:		5-8.cc pics.h

pics_main.o:	pics_main.cc pics.h

5_8_main:	pics_main.o 5_8.o

pics_main:	pics_main.o pics.o

split.o:	split.cc split.h

split_main.o:	split_main.cc split.h

split_main2.o:	split_main2.cc split.h

split_main:	split_main.o split.o

split_main2:	split_main2.o split.o

test:		all
	./fails_vec1 <../data/grades
	./fails_vec2 <../data/grades_my
	./fails_iters <../data/grades
	./fails_list <../data/grades
	./split_main < split_main.cc
	./split_main2 < split_main2.cc
	./pics_main
test_vec2:
	time ./fails_vec2 <../data/grades
test_vec_5_6:
	time ./fails_vec_5_6 <../data/grades
test_vec_huge:
	time ./fails_vec2 <../data/grades_my
test_5_6_huge:
	time ./fails_vec_5_6 <../data/grades_my
clobber:
	rm -f *.o *.exe core fails_vec1 fails_vec2 fails_iters fails_list \
	split_main split_main2 pics_main fails_vec_5_6
