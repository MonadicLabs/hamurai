#pragma once

#include <memory>
#include <map>

#include "port.h"
#include "event.h"
#include "identifiable.h"
#include "eventqueue.h"

namespace hamurai
{
class Pipeline;
class Kernel : public Identifiable
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

    virtual void onInit(){}

private:
    std::shared_ptr<Port> declare_port( const std::string& name,
                                        std::map< std::string, std::shared_ptr<Port> >& m );

    bool pushEvent(const Event &e );
    EventQueue _eventQueue;

    // Parent pipeline reference
    std::shared_ptr< Pipeline > _parent;

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
