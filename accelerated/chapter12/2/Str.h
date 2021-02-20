#ifndef STR_H
#define STR_H
#include <cstring>
#include<iterator>
#include <memory>
#include <algorithm>

class Str {
const static size_t initital_size = 10;
public:
typedef size_t size_type;
typedef char* iterator; 
typedef const char* const_iterator; 
char& operator[](size_type i) { return data[i]; }
const char& operator[](size_type i) const { return data[i]; }
friend std::istream& operator>>(std::istream& is, Str& str)
{
	is >> str.data;
	return is;
};
friend std::ostream& operator<<(std::ostream& os, const Str& str)
{
	os << str.data;
	return os;
};
// default constructor; create an empty Str
Str(){ 
	create();
}
// create a Str containing n copies of c
Str(size_type n, char c)
{
	create(n,c);
}
// create a Str from a null-terminated array of char
Str(const char* cp) {
	size_type src_size = std::strlen(cp);
	if(initital_size < src_size){
		s = src_size;
		data = new char[s];
	}
	
};

void append(const char c)
{
	if(avail == limit)
		grow();
	unchecked_append(c);

}
// create a Str from the range denoted by iterators b and 
 Str(const_iterator b, const_iterator e) {
	create(b,e);
}
private:
	size_t s;
	iterator data;
	iterator avail;
	iterator limit; 
	std::allocator<char> alloc;
	void create()
	{
		data=avail=limit=0;
	}
	void create(const_iterator b, const_iterator e)
	{
		alloc.allocate(e-b);
		std::uninitialized_copy(b,e,data);
	}
	void create(size_type s, char c)
	{
		data = alloc.allocate(s);
		limit=avail=data+s;
		std::uninitialized_fill(data, limit, c);
	}
	void grow(){
		// when growing, allocate twice as much space as currently in use
		size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
		// allocate new space and copy existing elements to the new space
		iterator new_data = alloc.allocate(new_size);
		iterator new_avail =std::uninitialized_copy(data, avail, new_data);
		// return the old space
		uncreate();
		// reset pointers to point to the newly allocated space
		data = new_data;
		// reset pointers to point to the newly allocated space
		data = new_data;
		avail = new_avail;
		limit = data + new_size;
	}
	void uncreate()
	{
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit-data);
		data=avail=limit=0;
	}

	void unchecked_append(const char c)
	{
		alloc.construct(avail++,c);
	}
};
#endif

