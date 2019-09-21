#ifndef GUARD_util 
#define GUARD_util

#include <vector>
#include <string>
#include "Pharse.h"

std::vector<Pharse> get_pharses( const std::string& );
std::vector<std::string> rotate(std::vector<std::string>&);
std::string::size_type left_part_length(const std::vector<std::string> &);
#endif
