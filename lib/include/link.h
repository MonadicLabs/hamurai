#pragma once

#include "port.h"

#include <memory>

namespace hamurai
{
    class Link
    {
    public:
        Link( std::shared_ptr<Port> in, std::shared_ptr<Port> out );
        virtual ~Link();

    private:

    protected:
        std::shared_ptr<Port> _in;
        std::shared_ptr<Port> _out;

    };
}
