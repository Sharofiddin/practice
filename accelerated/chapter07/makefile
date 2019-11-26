CXX = g++
CC = g++
CXXFLAGS = -I../chapter05  -I../chapter04 -I../chapter06

all:		wc xref grammar

Student_info.o: ../chapter04/Student_info.cc ../chapter04/Student_info.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/Student_info.cc
grade.o:
	$(CXX) $(CXXFLAGS) -c ../chapter06/grade.cc
median.o:	../chapter04/median.cc ../chapter04/median.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/median.cc
wc.o:		wc.cc

wc:		wc.o

xref.o:		xref.cc ../chapter05/split.h

xref:		xref.o split.o

grammar.o:	grammar.cc ../chapter05/split.h

student_info_map_to_letter.o: student_info_map_to_letter.cc  
student_info_map_to_letter: student_info_map_to_letter.o median.o grade.o Student_info.o
split.o:	../chapter06/split.cc ../chapter05/split.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/split.cc

grammar:	grammar.o split.o





test:		all
	./wc < wc.cc
	./xref < wc.cc
	./grammar <../data/grammar_input
test_student_info_map_to_letter: student_info_map_to_letter
	./student_info_map_to_letter<../data/grades 
clobber:
	rm -f *.o *.exe core wc xref grammar\
		test_student_info_map_to_letter
