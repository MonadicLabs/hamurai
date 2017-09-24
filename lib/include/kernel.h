#pragma once

#include <memory>
#include <map>

#include "port.h"
#include "event.h"
#include "identifiable.h"
#include "eventqueue.h"

namespace hamurai
{
class Graph;
class Kernel : public Identifiable, std::enable_shared_from_this<Kernel>
{

    friend class Port;
    friend class Graph;

public:
    Kernel();
    virtual ~Kernel();

private:
    std::shared_ptr<Port> declare_port( const std::string& name,
                                        std::map< std::string, std::shared_ptr<Port> >& m );

    void attachToGraph( Graph* parentGraph )
    {
        _parentGraph = parentGraph;
    }

    bool pushEvent(const Event &e );
    EventQueue _eventQueue;
    Graph* _parentGraph;

protected:
    std::map< std::string, std::shared_ptr< Port > > _inputs;
    std::map< std::string, std::shared_ptr< Port > > _outputs;

    std::shared_ptr< Port > declare_input( const std::string& name );
    std::shared_ptr< Port > declare_output( const std::string& name );
    bool queryEvent( Event& e, int64_t timeout_ms = -1 );
    void request_execution();

    std::shared_ptr<Port> in( const std::string& portName );
    std::shared_ptr<Port> out( const std::string& portName );

};
}
