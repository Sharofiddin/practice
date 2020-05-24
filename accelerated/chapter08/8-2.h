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

template <class T>
void swap( T &a, T&b )
{
    T c(a);
    a = b;
    b = c;
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

template <class It>
It search( It b, It e, It b2, It e2){
    while( b != e){
       if( *b == *b2 ){
           It temp = b;
           
           while( b2 != e2 ){
             temp++;
             b2++;
             if( b2 == e2)
                return b2;
             if( *temp != *b2 )
             {
                 break;
             }
             
           }
       }
        b++;
    }
    return e;
}

template <class It, class Pr>
It find_if(It b, It e, Pr p)
{
    while( b != e ){
        if(p(*b)){
            return b;
        }
        b++;
    }
    return e;
}

template <class It, class OutIt, class Target >
void remove_copy(It b, It e, OutIt d, Target t)
{
    while( b!= e )
    {
        if( *b != t )
        {
            *d = *b;
            d++;
        }
        b++;
    }
}

template <class It, class Target>
It remove(It b, It e, const Target &t)
{
    It res = b;
    while( b != e )
    {
        if( *b != t ){
            *res = *b;
            res++;
        }
        b++;
    }
    return res;
}

template <class It, class Pr>
It partition(It b, It e, Pr p)
{
    while(b != e ){
        if(!p(*b))
            break;
        b++;
    }
    if( b == e ){
        return b;
    }
    It res = b;
    b++;
    while( b!= e )
    {
        if(p(*b))
        {
            swap( *res, *b );
            ++res;
        }
        b++;
    }
    return res;
}
#endif
