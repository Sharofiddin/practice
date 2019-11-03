#ifndef GUARD_6_1_h
#define GUARD_6_1_h

#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>& v);

std::vector<std::string> frame(const std::vector<std::string>& v);

std::vector<std::string> hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right);

#endif
