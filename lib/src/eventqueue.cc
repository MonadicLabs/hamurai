
#include "eventqueue.h"
#include "lockfreequeue.h"

hamurai::EventQueue::EventQueue()
    :_backend(nullptr)
{
    _backend = (void*)(new LockFreeQueue<Event>());
}

hamurai::EventQueue::~EventQueue()
{
    if( _backend )
    {
        delete ((LockFreeQueue<Event>*)_backend);
    }
}

bool hamurai::EventQueue::enqueue(const hamurai::Event &item)
{
    LockFreeQueue<Event>* q = (LockFreeQueue<Event>*)_backend;
    return q->enqueue(item);
}

bool hamurai::EventQueue::enqueue(hamurai::Event &&item)
{
    LockFreeQueue<Event>* q = (LockFreeQueue<Event>*)_backend;
    return q->enqueue(item);
}

bool hamurai::EventQueue::dequeue(hamurai::Event &item, int64_t timeout_ms)
{
    LockFreeQueue<Event>* q = (LockFreeQueue<Event>*)_backend;
    return q->dequeue(item, timeout_ms);
}
