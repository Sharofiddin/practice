#ifndef GUARD_Pharse
#define GUARD_Pharse
#include <iostream>
#include <vector>
#include <string>

struct Pharse
{
	std::vector<std::string> words;
	std::vector<std::string>::size_type separator;
};

bool compare(const Pharse&, const Pharse& );
void printPharse(const Pharse&, std::string::size_type );
std::string low_case(const std::string &);
std::string join_words(const std::vector<std::string> &);
#endif

