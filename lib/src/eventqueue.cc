
#include "eventqueue.h"

#include <blockingconcurrentqueue.h>

using namespace moodycamel;

hamurai::EventQueue::EventQueue()
    :_backend(nullptr)
{
    _backend = (void*)(new BlockingConcurrentQueue<Event>());
}

hamurai::EventQueue::~EventQueue()
{
    if( _backend )
    {
        delete ((BlockingConcurrentQueue<Event>*)_backend);
    }
}

bool hamurai::EventQueue::enqueue(const hamurai::Event &item)
{
    BlockingConcurrentQueue<Event>* q = (BlockingConcurrentQueue<Event>*)_backend;
    return q->enqueue( item );
}

bool hamurai::EventQueue::dequeue(hamurai::Event &item, int64_t timeout_ms)
{
    BlockingConcurrentQueue<Event>* q = (BlockingConcurrentQueue<Event>*)_backend;

    // If timeout is 0, then we wait indefinitelely
    if( timeout_ms == 0 )
    {
        q->wait_dequeue( item );
        return true;
    }
    else if( timeout_ms < 0 )
    {
        return q->try_dequeue( item );
    }
    else if( timeout_ms > 0 )
    {
        return q->wait_dequeue_timed( item, timeout_ms * 1000 );
    }

    return false;
}


