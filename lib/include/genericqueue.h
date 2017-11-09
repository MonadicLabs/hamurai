#pragma once

#include <cstdint>

namespace hamurai
{
template< class T >
class GenericQueue
{
public:
    virtual ~GenericQueue() = default;
    virtual bool enqueue( T const& item ) = 0;
    virtual bool enqueue( T&& item ) = 0;
    virtual bool dequeue(T &item, int64_t timeout_ms ) = 0;
    virtual int size(){ return -1; }
    virtual void transferTo( GenericQueue<T>& other )
    {
        while( this->size() )
        {
            T item;
            if( this->dequeue(item, -1) )
            {
                other.enqueue(item);
            }
        }
    }
};
}
