#ifndef GUARD_pics_h
#define GUARD_pics_h

#include <string>

std::string::size_type width(const Vec<std::string>& v);

Vec<std::string> frame(const Vec<std::string>& v);

Vec<std::string> vcat(const Vec<std::string>& top,
                              const Vec<std::string>& bottom);

Vec<std::string> hcat(const Vec<std::string>& left,
                              const Vec<std::string>& right);

#endif
