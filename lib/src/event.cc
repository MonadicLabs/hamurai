
#include "event.h"

hamurai::Event::Event(hamurai::Event::Type eventType, std::shared_ptr<hamurai::Kernel> k)
    :_type(eventType), _kernel(k)
{

}
