CXX = g++
CC = g++

test:	test_vec test_list	 	
test_vec: main_vec
	time ./main_vec < grades
test_list: main_list
	time ./main_list < grades

all:		main_vec main_list	

median.o:	median.cc median.h
	$(CXX) -c median.cc

Student_info.o:	Student_info.cc Student_info.h
	$(CXX)  -c Student_info.cc

grade.o:	grade.cc grade.h

main_vec.o:	main_vec.cc grade.h Student_info.h median.h

main_list.o:	main_list.cc grade.h Student_info.h median.h

main_vec:	main_vec.o grade.o  median.o Student_info.o 

main_list:	main_list.o grade.o median.o Student_info.o

clobber:
	rm -f *.o  main_vec main_list
