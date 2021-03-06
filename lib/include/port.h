#pragma once

#include "dataqueue.h"
#include "dataitem.h"
#include "some.h"

#include <string>

namespace hamurai
{
    class Kernel;
    class Port
    {

        friend class Kernel;

    public:
        bool push();

    private:
        Kernel* _parent;
        std::string _ownName;
        DataQueue _dataQueue;

    protected:
        Port( Kernel* parent, const std::string& ownName )
            :_parent(parent), _ownName(ownName)
        {}

    };
}
