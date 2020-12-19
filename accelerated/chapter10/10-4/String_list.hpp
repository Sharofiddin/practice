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
#include <list>
struct node{
	std::string val;
	node *next;
	node *prev;
	node():next(nullptr),prev(nullptr){}
} ;
class String_list
{
				public:
								String_list();
								~String_list();
								void push_back(const std::string&);
								void print();
								
				private:
								node *head;

};


#endif