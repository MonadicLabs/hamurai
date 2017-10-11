#pragma once

#include "id.h"

namespace hamurai
{
    class Identifiable
    {
    public:
        Id id()
        {
            return _id;
        }

    private:

    protected:
        Id _id;
    };
}
