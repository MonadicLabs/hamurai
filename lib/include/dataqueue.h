#pragma once

#include "genericqueue.h"
#include "any.h"

#include <memory>

namespace hamurai
{
class DataQueue : public GenericQueue< hamurai::Any >
{
public:
    DataQueue();
    virtual ~DataQueue();

    virtual bool enqueue( Any const& item );
    virtual bool enqueue( Any && item );
    virtual bool dequeue( Any & item, int64_t timeout_ms );

    int size();

private:

protected:
    void * _backend;

};
}
