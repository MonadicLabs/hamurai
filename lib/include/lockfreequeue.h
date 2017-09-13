#pragma once

#include "genericqueue.h"
#include <blockingconcurrentqueue.h>

namespace hamurai
{
template< class T >
class LockFreeQueue : public GenericQueue
{
public:
    LockFreeQueue()
    {

    }

    virtual ~LockFreeQueue()
    {

    }

    bool enqueue( T& item )
    {
        return _queue.enqueue( item );
    }

    bool dequeue( T& item )
    {
        return _queue.wait_dequeue_timed( item, 10000 );
    }

private:

protected:
    moodycamel::BlockingConcurrentQueue< T > _queue;

};
}
