<<<<<<< HEAD
#include <cctype>
#include <iostream>
#include <iterator>

#ifndef _MSC_VER
using std::isspace;
#endif


#include "Str.h"

using std::istream;
using std::istream_iterator;
using std::ostream;

ostream& operator<<(ostream& os, const Str& s)
{
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

// this code won't compile quite yet
istream& operator>>(istream& is, Str& s)
{
	// obliterate existing value(s)
	s.data->clear();

	// read and discard leading whitespace
	char c;
	while (is.get(c) && isspace(c))
		;	// nothing to do, except testing the condition

	// if still something to read, do so until next whitespace character
	if (is) {
		do	s.data->push_back(c);      // `\f(BIcompile error!, data' is `private'
		while (is.get(c) && !isspace(c));

		// if we read whitespace, then put it back on the stream
		if (is)
			is.unget();
	}

	return is;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}

istream& getline(istream&is, Str& s)
{
	s.data->clear();

	char c;
        while (is.get(c) && isspace(c))
                ;       // \f2nothing to do, except testing the condition\fP

        // \f2if still something to read, do so until next whitespace character\fP
        if (is) {
                do      s.data->push_back(c);
                while (is.get(c) && c != '\n');

                // \f2if we read whitespace, then put it back on the stream\fP
                if (is)
                        is.unget();
        }

        return is;
}

=======
#include "Str.h"
#include <iostream>

char &Str::operator[](Str::size_type i) { data_p.make_unique(); return (*data_p)[i]; }
const char &Str::operator[](size_type i) const { return (*data_p)[i]; }
std::istream &operator>>(std::istream &is, Str &str)
{
    // we can not use istream_iterator because it has not got unget()
    //std::istream_iterator<char> it(is);
    // obliterate existing value(s)
    str.uncreate();
    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ; // nothing to do, except testing the condition
    // if still something to read, do so until next whitespace character
    if (is)
    {
        do
            str.append(c);
        // compile error! , data is private
        while (is.get(c) && !isspace(c));
        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, const Str &str)
{
    std::ostream_iterator<char> osit(os);
    copy(str.begin(), str.end(), osit);
    return os;
}

bool operator>(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) > 0;
}
bool operator<(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) < 0;
}
bool operator>=(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) >= 0;
}
bool operator<=(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) <= 0;
}
bool operator==(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) == 0;
}
bool operator!=(const Str &s1, const Str &s2)
{
    return strcmp(s1.c_str(), s2.c_str()) != 0;
}

Str operator+(const Str &s1, const Str &s2)
{
    Str res(s1);
    return res.append(s2);
}

Str operator+(const char *c_arr, const Str &str)
{
    return Str(c_arr).append(str);
}

Str operator+( const Str &str, const char *c_arr)
{
    return Str(str).append(c_arr);
}

Str &Str::operator+=(const Str &s)
{
    return append(s);
}
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
Str::Str(const Ptr<char[]> cp)
{
    size_type src_size = std::strlen(*cp);
    create(cp, cp + src_size);
};

Str::Str(const Str &src)
{
    create(src.begin(), src.end());
}
Str &Str::append(const char c)
{
    if (avail == limit)
        grow();
    unchecked_append(c);
    return *this;
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
    ptrdiff_t buff_size = e - b;
    data_p = alloc.allocate(buff_size);
    avail = limit = data_p + buff_size;
    std::uninitialized_copy(b, e, data_p);
}
void Str::create(size_type s, char c)
{
    data_p = alloc.allocate(s);
    limit = avail = data_p + s;
    std::uninitialized_fill(data_p, limit, c);
}

Str::size_type Str::copy(char *dest, size_type count, size_type pos) const
{
    size_type size = avail - data_p;
    if (pos > size)
    {
        std::cerr << "starting position over size\n";
        return 0;
    }
    if (pos + count > size)
        count = size - pos;
    for (size_type i = 0; i < count; i++)
        dest[i] = data_p[i + pos];
    return count;
}

void Str::grow()
{
    // when growing, allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data_p), ptrdiff_t(1));
    // allocate new space and copy existing elements to the new space
    grow(new_size);
}
void Str::grow(size_type new_size)
{
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data_p, avail, new_data);
    // return the old space
    uncreate();
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

const char* Str::c_str() const
{
    return *data_p;
}

const char* Str::data() const
{
    return *data_p;
}
Str::size_type Str::size() const
{
    return avail - data_p;
}
Str &Str::append(const Str &s)
{
    size_type new_size = size() + s.size();
    if (limit <= avail + s.size())
        grow(3 * new_size / 2);
    avail = std::uninitialized_copy(s.begin(), s.end(), avail);
    return *this;
}
bool Str::empty() const
{
    return data_p == avail;
}
Str::operator bool() const
{
    return !empty();
}

std::istream &getline(std::istream &is, Str &s)
{
    s.uncreate();
    char c;
    do
        s.append(c);
    while (is.get(c) && c != '\n');
    return is;
}
Str Str::substr(size_type pos,  size_type count) const
{
    size_type st_size = size();
    if(pos >= st_size )
        throw std::domain_error("out of the range");
    if((pos + count) > st_size)
        count = st_size - pos;
    return Str(data_p+pos, data_p+pos+count);
}
>>>>>>> 40a451bf60b409436ad660b7cd8e4ae16ea4e031
