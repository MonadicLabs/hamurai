
#include "kernel.h"
#include "exception.h"
#include "graph.h"
#include "event.h"

#include <iostream>

using namespace std;

hamurai::Kernel::Kernel()
    :_parentManager(nullptr), _curState(STOPPED)
{

}

hamurai::Kernel::~Kernel()
{
    schedule( std::make_shared<Event>( Event::HAMURAI_EVENT_KERNEL_DESTRUCTION, shared_from_this() ) );
}

void hamurai::Kernel::start()
{
    cerr << "scheduling kernel start() " << this << endl;
    setState( Kernel::STARTED );
    schedule( std::make_shared<Event>( Event::HAMURAI_EVENT_INIT_QUERY, shared_from_this() ) );
}

void hamurai::Kernel::stop()
{
    setState( Kernel::STOPPED );
    schedule( std::make_shared<Event>( Event::HAMURAI_EVENT_KERNEL_STOP, shared_from_this() ) );
}

void hamurai::Kernel::schedule(std::shared_ptr<hamurai::Event> e)
{
    if( _parentManager )
    {
        // cerr << "calling receive on " << _parentManager << " type=" << e->type() << endl;
        _parentManager->receive( e );
    }
    else
    {
        // cerr << "No event manager set :/" << endl;
    }
}

void hamurai::Kernel::enable_idle()
{
    schedule( std::make_shared<Event>( Event::HAMURAI_EVENT_KERNEL_START_IDLE, shared_from_this() ) );
}

std::shared_ptr<hamurai::Port> hamurai::Kernel::declare_port(const string &name, std::map<string, std::shared_ptr<hamurai::Port> > &m)
{
    std::shared_ptr<Port> ret = nullptr;
    if( m.find( name ) != m.end() )
    {
        HAMURAI_THROW( std::string("Port \"") + name + std::string("\" already defined !") );
    }
    else
    {
        ret = shared_ptr<Port>(new Port( this, name ));
        m.insert( make_pair( name, ret ) );
    }
    return ret;
}

bool hamurai::Kernel::pushEvent(hamurai::Event const& e)
{
    // return _eventQueue.enqueue(e);
}

std::shared_ptr<hamurai::Port> hamurai::Kernel::declare_input(const std::string &name)
{
    try{
        return declare_port( name, _inputs );
    } catch( Exception& e )
    {
        HAMURAI_THROW( std::string("Input port \"") + name + std::string("\" already defined !") );
    }
}

std::shared_ptr<hamurai::Port> hamurai::Kernel::declare_output(const string &name)
{
    try{
        return declare_port( name, _outputs );
    }
    catch( Exception& e )
    {
        HAMURAI_THROW( std::string("Output port \"") + name + std::string("\" already defined !") );
    }
}

bool hamurai::Kernel::queryEvent(hamurai::Event &e, int64_t timeout_ms)
{
    // return _eventQueue.dequeue( e, timeout_ms );
    return false;
}

std::shared_ptr<hamurai::Port> hamurai::Kernel::in(const string &portName)
{
    std::shared_ptr<Port> ret = nullptr;
    if( _inputs.find( portName ) == _inputs.end() )
    {
        HAMURAI_THROW( std::string("Input port \"") + portName + std::string("\" does not exist !") );
    }
    else
    {
        ret = _inputs[ portName ];
    }
    return ret;
}

std::shared_ptr<hamurai::Port> hamurai::Kernel::out(const string &portName)
{
    std::shared_ptr<Port> ret = nullptr;
    if( _outputs.find( portName ) == _outputs.end() )
    {
        HAMURAI_THROW( std::string("Output port \"") + portName + std::string("\" does not exist !") );
    }
    else
    {
        ret = _outputs[ portName ];
    }
    return ret;
}
