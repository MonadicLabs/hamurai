
#include "eventqueue.h"
#include "lockfreequeue.h"

hamurai::EventQueue::EventQueue()
    :_backend(nullptr)
{
    _backend = (void*)(new LockFreeQueue<std::shared_ptr<Event>>());
}

hamurai::EventQueue::~EventQueue()
{
    if( _backend )
    {
        delete ((LockFreeQueue<std::shared_ptr< std::shared_ptr<Event> >>*)_backend);
    }
}

bool hamurai::EventQueue::enqueue(const std::shared_ptr<Event> &item)
{
    LockFreeQueue< std::shared_ptr<Event> > * q = (LockFreeQueue< std::shared_ptr<Event> >*)_backend;
    return q->enqueue(item);
}

bool hamurai::EventQueue::enqueue( std::shared_ptr<Event> &&item)
{
    LockFreeQueue< std::shared_ptr<Event> >* q = (LockFreeQueue< std::shared_ptr<Event> >*)_backend;
    return q->enqueue(item);
}

bool hamurai::EventQueue::dequeue( std::shared_ptr<Event> &item, int64_t timeout_ms)
{
    LockFreeQueue< std::shared_ptr<Event> >* q = (LockFreeQueue<std::shared_ptr<Event> >*)_backend;
    return q->dequeue(item, timeout_ms);
}

int hamurai::EventQueue::size()
{
    LockFreeQueue< std::shared_ptr<Event> >* q = (LockFreeQueue<std::shared_ptr<Event> >*)_backend;
    return q->size();
}
