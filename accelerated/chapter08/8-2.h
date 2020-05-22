#ifndef CHAPTER_8_EX_2
#define CHAPTER_8_EX_2
#include <iostream>
using std::cout;
template <class It1, class Pr>
    bool equal(It1 begin, It1 end, It1 it)
{
    while (begin != end)
    {
        if (*begin != *it)
            return false;
        begin++;
        it++;
    }
    return true;
}

template< class It, class Target >
It find(It b, It e, Target t){
    while( b != e ){
        if( t == *b )
            return b;
        b++;
    }
    return e;
}   

template <class It >
void copy(It begin, It end, It target){
    while (begin != end)
    {
        *target = *begin;
        target++;
        begin++;
    }
}

template <class It, class Pr>
void remove_copy_if( It b, It e, It d, Pr p)
{
    while (b != e )
    {
        if(!p(*b)){
            *d = *b;
            d++;
        }
        b++;

    }
    
}

template <class It, class Func>
void transform( It b, It e, It d, Func f){

    while( b!= e ){
        *d = f(*b);
        b++;
        d++;
    }
}

template <class It, class Target>
Target accumulate(It b, It e, Target t){
    while (b != e)
    {
        t += *b;
        b++;
    }
    return t;
}
#endif
