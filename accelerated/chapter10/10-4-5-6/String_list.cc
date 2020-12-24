#include "String_list.hpp"
#include <iostream>
String_list::String_list(){
    head = nullptr;
};
String_list::~String_list(){};
void String_list::push_back(const std::string& val)
{
   node *new_node = new node;
   node *last = head;
   new_node->next = nullptr;
   new_node->val = val;

   if(head == nullptr){
       new_node->prev = nullptr;
       head = new_node;
       return;
   }

   while(last->next){
       last = last->next;
   }
   last->next = new_node;   
   new_node->prev = last;
}

void String_list::print()
{
    while(head != nullptr){
        std::cout << head->val << '\n';
        head = head->next;
    }
}

