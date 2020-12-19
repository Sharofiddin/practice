CXX = g++
CC = g++
CCFLAGS = -Wall -Werror -Wextra
CXXFLAGS = -Wall -Werror -Wextra
debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: test

String_list.o: String_list.cc String_list.hpp 
test.o:	test.cc String_list.hpp
test: test.o String_list.o
clobber:
	rm -rf *.o test