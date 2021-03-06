/*
 * =====================================================================================
 *
 *       Filename:  String_list.h
 *
 *    Description: String list impl 
 *
 *        Version:  1.0
 *        Created:  12/17/2020 10:56:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sharofiddin Pardayev (p.sh.t), pardayev.sharofddin@gmail.com
 *        Company:  BIS, Tashkent
 *
 * =====================================================================================
 */
#ifndef STRING_LIST_GUARD
#define STRING_LIST_GUARD
#include <string>
struct node
{
	std::string val;
	node *next;
	node *prev;
	node() : next(nullptr), prev(nullptr) {}
};
class String_list
{
public:
	typedef node *iterator;
	String_list();
	~String_list();
	void push_back(const std::string &);
	node *begin() { return head; }
	node *end() { return nullptr; }
	void print();

private:
	node *head;
};

#endif