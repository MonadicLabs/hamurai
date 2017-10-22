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

};
}
