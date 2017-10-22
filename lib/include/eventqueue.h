#pragma once

#include "genericqueue.h"
#include "event.h"

namespace hamurai
{
class EventQueue : public GenericQueue< std::shared_ptr<Event> >
{
public:
    EventQueue();
    virtual ~EventQueue();

    virtual bool enqueue( std::shared_ptr<Event> const& item );
    virtual bool enqueue( std::shared_ptr<Event> && item );
    virtual bool dequeue( std::shared_ptr<Event> & item, int64_t timeout_ms );

    int size();

private:

protected:
    void * _backend;

};
}
