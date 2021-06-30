#ifndef _REF_COUNTER_GUARD
#define _REF_COUNTER_GUARD
#include <cstddef>
class Ref_counter
{
private:
    std::size_t *counter;
public:
    Ref_counter():counter(new size_t(1))
    {

    };
    Ref_counter(const Ref_counter& ref_counter):counter(ref_counter.counter)
    {
        (*counter)++;
    };

    Ref_counter operator--()
    {
        if(--(*counter) == 0)
            delete counter;
        return *this;
    };

    Ref_counter operator++()
    {
        (*counter)++;
        return *this;
    };

    Ref_counter operator++() const
    {
        (*counter)++;
        return *this;
    };


    std::size_t val()
    {
        return *counter;
    };
    operator bool() const
    {
        return counter;
    };
};
#endif