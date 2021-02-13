CC = g++
CXX = g++
CXXFLAGS = -I ./ -I../
main: 	main.cc List.hpp
main_student.o:	main_student.cc
main_student: main_student.o ../Student_info.o ../grade.o
test: main
	./main
clobber:
	rm -rf *.o main
