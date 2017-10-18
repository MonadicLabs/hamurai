#pragma once

#include <memory>
#include <map>

#include "port.h"
#include "event.h"
#include "identifiable.h"
#include "eventqueue.h"
#include "eventmanager.h"

namespace hamurai
{

class Pipeline;
class Kernel : public Identifiable, public EventManager, public std::enable_shared_from_this<Kernel>
{

    friend class Port;
    friend class Pipeline;

public:

    typedef enum
    {
        NOT_INITIALIZED = 0,
        TERMINATED,
        NORMAL,
        SUSPENDED,
        INACTIVE
    } State;

    Kernel();
    virtual ~Kernel();

    virtual void init(){}
    virtual void tick(){}
    virtual void start();
    virtual void stop();

    virtual void schedule( std::shared_ptr<Event> e );

    void setEventManager( std::shared_ptr<EventManager> em )
    {
        _parentManager = em;
    }

    std::shared_ptr<EventManager> getEventManager()
    {
        return _parentManager;
    }

private:
    std::shared_ptr<Port> declare_port( const std::string& name,
                                        std::map< std::string, std::shared_ptr<Port> >& m );

    bool pushEvent(const Event &e );
    EventQueue _eventQueue;

    // Parent pipeline reference
    std::shared_ptr< EventManager > _parentManager;

    // Kernel current state
    State _curState;

protected:
    std::map< std::string, std::shared_ptr< Port > > _inputs;
    std::map< std::string, std::shared_ptr< Port > > _outputs;

    std::shared_ptr< Port > declare_input( const std::string& name );
    std::shared_ptr< Port > declare_output( const std::string& name );
    bool queryEvent( Event& e, int64_t timeout_ms = -1 );

    // IO
    std::shared_ptr<Port> in( const std::string& portName );
    std::shared_ptr<Port> out( const std::string& portName );

    // STATE
    State getState();
    void setState();

};
}
