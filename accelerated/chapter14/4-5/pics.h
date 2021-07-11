#ifndef GUARD_pics_h
#define GUARD_pics_h

#include "Str.h"
#include "Vec.h"

Str::size_type width(const Vec<Str>& v);

Vec<Str> frame(const Vec<Str>& v);

Vec<Str> vcat(const Vec<Str>& top,
                              const Vec<Str>& bottom);

Vec<Str> hcat(const Vec<Str>& left,
                              const Vec<Str>& right);

#endif
