#pragma once

#include "genericqueue.h"
#include <blockingconcurrentqueue.h>

namespace hamurai
{
template< class T >
class LockFreeQueue : public GenericQueue<T>
{
public:
    LockFreeQueue()
    {

    }

    virtual ~LockFreeQueue()
    {

    }

    virtual bool enqueue( T const& item )
    {
        return _queue.enqueue( item );
    }

    virtual bool enqueue( T&& item )
    {
        return _queue.enqueue( item );
    }

    virtual bool dequeue(T &item, int64_t timeout_ms )
    {
        if( timeout_ms == 0 )
        {
            _queue.wait_dequeue( item );
            return true;
        }
        else if( timeout_ms < 0 )
        {
            return _queue.try_dequeue( item );
        }
        else if( timeout_ms > 0 )
        {
            return _queue.wait_dequeue_timed( item, timeout_ms * 1000 );
        }
        return false;
    }

    virtual int size()
    {
        return _queue.size_approx();
    }

private:

protected:
    moodycamel::BlockingConcurrentQueue< T > _queue;

};
}
