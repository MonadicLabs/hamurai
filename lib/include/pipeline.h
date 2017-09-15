#pragma once

#include <memory>
#include <map>

#include "kernel.h"

namespace hamurai
{
    class Pipeline
    {
    public:

    private:
        std::map< hamurai::Id, std::shared_ptr< hamurai::Kernel > > _nodes;
        // std::map< hamurai::Id, std::shared_ptr< hamurai::Kernel > > _nodes;

    protected:

    };
}
