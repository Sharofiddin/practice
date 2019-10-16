CXX = g++
CC = g++
CXXFLAGS = -I ../../chapter04 -I ../../chapter05
all:		fails_vec_5_6 


fails_vec_5_6.o:	fails_vec_5_6.cc ../grade.h ../../chapter04/Student_info.h

fails_vec_5_6:		fails_vec_5_6.o ../ext_main.o ../grade.o ../median.o ../Student_info.o	

test:		all
	./fails_vec_5_6 <../../data/grades

clobber:
	rm -f *.o  fails_vec_5_6 
