#pragma once

#include "dataitem.h"

namespace hamurai
{
    class DataQueue
    {
    public:
        DataQueue();
        virtual ~DataQueue();

        bool enqueue( DataItem const& item );
        bool dequeue( DataItem& item );

    private:
        void* _backend;

    };
}
