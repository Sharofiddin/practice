CXX = g++
CC = g++
CXXFLAGS = -I../chapter04 -I../chapter05

all:		split_main palin urls_main grade_analysis ext_fails1\
			ext_fails2 6-5 test_universal_analysis ext_didnt\
			ext_by_creteria

median.o:	../chapter04/median.cc ../chapter04/median.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/median.cc

Student_info.o:	../chapter04/Student_info.cc ../chapter04/Student_info.h
	$(CXX) $(CXXFLAGS) -c ../chapter04/Student_info.cc

split.o:	split.cc ../chapter05/split.h

split_main.o:	../chapter05/split_main.cc ../chapter05/split.h
	$(CXX) $(CXXFLAGS) -c ../chapter05/split_main.cc

split_main:	split_main.o split.o

palin.o:	palin.cc

urls.o:		urls.cc urls.h

urls_main.o:	urls_main.cc urls.h

urls_main:	urls_main.o urls.o

grade.o:	grade.cc grade.h

grade_check.o:	grade_check.cc

analysis.o:	analysis.cc analysis.h

grade_analysis.o: grade_analysis.cc analysis.h

grade_analysis:	grade_analysis.o analysis.o grade_check.o \
		grade.o median.o Student_info.o

ext_main.o:	../chapter05/ext_main.cc grade.h ../chapter04/Student_info.h \
		../chapter04/median.h
	$(CXX) $(CXXFLAGS) -c ../chapter05/ext_main.cc
ext_by_creteria_main.o: ext_by_creteria_main.cc grade.h ../chapter04/Student_info.h \
		../chapter04/median.h
	$(CXX) $(CXXFLAGS) -c ext_by_creteria_main.cc
ext_by_creteria.o: ext_by_creteria.cc grade.h ../chapter04/Student_info.h \
		../chapter04/median.h
ext_by_creteria: ext_by_creteria_main.o ext_by_creteria.o grade_check.o grade.o \
				 median.o Student_info.o
ext_fails1.o:	ext_fails1.cc grade.h ../chapter04/Student_info.h \
		../chapter04/median.h

ext_fails2.o:	ext_fails2.cc grade.h ../chapter04/Student_info.h \
		../chapter04/median.h

ext_fails1:	ext_main.o ext_fails1.o grade.o median.o Student_info.o

ext_fails2:	ext_main.o ext_fails2.o grade.o median.o Student_info.o

6-1.o:		6-1.h 6-1.cc

6-1_main.o:	6-1_main.cc 6-1.h 

6-1_main:	6-1_main.o 6-1.o

6-5.o:		6-5.cc analysis.h

test_universal_analysis.o: test_universal_analysis.cc analysis.h 

test_universal_analysis: test_universal_analysis.o analysis.o grade_check.o \
		grade.o median.o Student_info.o

ext_didnt.o : analysis.h ext_didnt.cc
ext_didnt: ext_didnt.o analysis.o grade_check.o \
		grade.o median.o Student_info.o

6-5:	     6-5.o analysis.o grade_check.o\
				grade.o median.o Student_info.o

main_urls.o:	main_urls.cc urls.h

main_urls:	main_urls.o urls.o

test:		all
	./split_main <split.cc
	./palin <../data/palins_input
	./urls_main <../data/urls.htm
	./grade_analysis <../data/grades
	./ext_fails1 <../data/grades
	./ext_fails2 <../data/grades
	./6-5 <../data/grades
	./test_universal_analysis <../data/grades
	./ext_didnt <../data/grades
	./ext_by_creteria <../data/grades

test_6-1:
	./6-1_main

test_main_urls:
	./main_urls <../data/urls.htm
test_6_5:
	./6-5 <../data/grades
test_ext_didnt: ext_didnt
	./ext_didnt <../data/grades
test_ext_by_creteria: ext_by_creteria
	./ext_by_creteria <../data/grades
clobber:
	rm -rf *.o *.exe core split_main palin urls_main grade_analysis \
	ext_fails1 ext_fails2 6-1_main main_urls\
	6-5 6-3 6-4-3 6-4-2 6-4 ext_didnt ext_by_creteria

