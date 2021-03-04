#include "Str.h"
#include <iostream>
char &Str::operator[](Str::size_type i) { return data_p[i]; }
const char &Str::operator[](size_type i) const { return data_p[i]; }
std::istream &operator>>(std::istream &is, Str &str)
{
    is >> str.data_p;
    return is;
};
std::ostream &operator<<(std::ostream &os, const Str &str)
{
    os << str.data_p;
    return os;
};
// default constructor; create an empty Str
Str::Str()
{
    create();
}
// create a Str containing n copies of c
Str::Str(size_type n, char c)
{
    create(n, c);
}
// create a Str from a null-terminated array of char
Str::Str(const char *cp)
{
    size_type src_size = std::strlen(cp);
    create(cp, cp + src_size);
};

Str::Str(const Str& src)
{
    create(src.begin(), src.end());
}
void Str::append(const char c)
{
    if (avail == limit)
        grow();
    unchecked_append(c);
}
// create a Str from the range denoted by iterators b and
Str::Str(const_iterator b, const_iterator e)
{
    create(b, e);
}

Str::iterator Str::begin()
{
    return data_p;
}
Str::iterator Str::end()
{
    return avail;
}
Str::const_iterator Str::begin() const
{
    return data_p;
}
	
Str::const_iterator Str::end() const
{
    return avail;
}
void Str::create()
{
    data_p = avail = limit = 0;
}
void Str::create(const_iterator b, const_iterator e)
{
    ptrdiff_t buff_size = e-b;
    data_p = alloc.allocate(buff_size);
    avail=limit=data_p+buff_size;
    std::uninitialized_copy(b, e, data_p);
}
void Str::create(size_type s, char c)
{
    data_p = alloc.allocate(s);
    limit = avail = data_p + s;
    std::uninitialized_fill(data_p, limit, c);
}

Str::size_type Str::copy( char* dest, size_type count, size_type pos) const
{
    size_type size = end() - begin();
    if(pos > size) {
        std::cerr << "starting position over size\n";
        return -1;
    }
    if( pos + count > size )
        count = size - pos;
    for(size_type i = 0; i < count; i++)
        dest[i] = data_p[ i + pos ];
    return count;
}

void Str::grow()
{
    // when growing, allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data_p), ptrdiff_t(1));
    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data_p, avail, new_data);
    // return the old space
    uncreate();
    // reset pointers to point to the newly allocated space
    data_p = new_data;
    // reset pointers to point to the newly allocated space
    data_p = new_data;
    avail = new_avail;
    limit = data_p + new_size;
}
void Str::uncreate()
{
    iterator it = avail;
    while (it != data_p)
        alloc.destroy(--it);
    alloc.deallocate(data_p, limit - data_p);
    data_p = avail = limit = 0;
}

void Str::unchecked_append(const char c)
{
    alloc.construct(avail++, c);
}

const char * Str::c_str() const 
{
    return data_p;
}

const char * Str::data() const 
{
    return data_p;
}