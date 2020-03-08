#ifndef CHAPTER_8_EX_2
#define CHAPTER_8_EX_2

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
#endif