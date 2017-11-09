
#include "dataqueue.h"
#include "lockfreequeue.h"

hamurai::DataQueue::DataQueue()
    :_backend(nullptr)
{
    _backend = (void*)(new LockFreeQueue<Any>());
}

hamurai::DataQueue::~DataQueue()
{
    if( _backend )
    {
        delete ((LockFreeQueue<Any>*)_backend);
    }
}

bool hamurai::DataQueue::enqueue(const Any &item)
{
    LockFreeQueue<Any> * q = (LockFreeQueue<Any>*)_backend;
    return q->enqueue(item);
}

bool hamurai::DataQueue::enqueue( Any &&item)
{
    LockFreeQueue< Any >* q = (LockFreeQueue< Any >*)_backend;
    return q->enqueue(item);
}

bool hamurai::DataQueue::dequeue( Any &item, int64_t timeout_ms)
{
    LockFreeQueue< Any >* q = (LockFreeQueue<Any>*)_backend;
    return q->dequeue(item, timeout_ms);
}

int hamurai::DataQueue::size()
{
    LockFreeQueue< Any >* q = (LockFreeQueue<Any>*)_backend;
    return q->size();
}
