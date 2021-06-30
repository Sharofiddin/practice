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
        counter++;
    };
    ~Ref_counter()
    {
        if(--counter == 0)
        {
            delete counter;
        }
    }

};
#endif