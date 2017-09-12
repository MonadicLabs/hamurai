#pragma once

#include <cstdint>

#include "event.h"

namespace hamurai
{
    class EventQueue
    {
    public:
        EventQueue();
        virtual ~EventQueue();

        bool enqueue( Event const& item );
        bool enqueue( Event&& item );

        bool dequeue(Event &item, int64_t timeout_ms );

    private:
        void* _backend;

    };
}
