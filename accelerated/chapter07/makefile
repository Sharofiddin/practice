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

xref.o:		xref.cc ../chapter06/urls.h

xref:		xref.o urls.o

grammar.o:	grammar.cc ../chapter05/split.h

student_info_map_to_letter.o: student_info_map_to_letter.cc  
student_info_map_to_letter: student_info_map_to_letter.o median.o grade.o Student_info.o
split.o:	../chapter06/split.cc ../chapter05/split.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/split.cc
urls.o:	../chapter06/urls.cc ../chapter06/urls.h
	$(CXX) $(CXXFLAGS) -c ../chapter06/urls.cc

grammar:	grammar.o split.o
grammar_d: grammar.o split.o -g

grammar_list: grammar_list.o split.o

test:		all
	./wc < wc.cc
	./xref < wc.cc
	./grammar <../data/grammar_input
test_student_info_map_to_letter: student_info_map_to_letter
	./student_info_map_to_letter<../data/grades 
test_grammar_list: grammar_list
		./grammar_list <../data/grammar_input
clobber:
	rm -f *.o *.exe *.out core wc xref grammar\
		test_student_info_map_to_letter\
		grammar_list student_info_map_to_letter\
		myrand
