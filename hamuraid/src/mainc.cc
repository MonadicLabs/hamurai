#include <iostream>

#include <unistd.h>
#include <math.h>

#include <hamurai.h>

using namespace std;
using namespace hamurai;

class RandomNumberGenerator : public hamurai::Kernel
{
public:
    RandomNumberGenerator()
    {
        declare_output( "output" );
    }

    virtual void init()
    {
        if( getState() == Kernel::STARTED )
        {
            cerr << "INIT ! " << this << endl;
            schedule( make_shared< Event >( Event::HAMURAI_EVENT_TICK, shared_from_this() ) );
        }
    }

    virtual void tick()
    {
        if( getState() == Kernel::STARTED )
        {
            cerr << "TICK ! " << this << endl;
            sleep(1);
            double popo = exp( 1566.3 ) * log( pow( 23, 4.6 ) );
            // schedule( make_shared< Event >( Event::HAMURAI_EVENT_TICK, shared_from_this() ) );
        }
    }
};

class TestKernel : public hamurai::Kernel
{
public:
    TestKernel()
    {
        declare_input( "popo" );
        declare_input( "papapa" );
        declare_output( "papa" );

        for( int i = 0; i < 10; ++i )
        {
            in("popo")->push( DataItem() );
        }
    }
};

int main( int argc, char** argv )
{

    std::shared_ptr<hamurai::ExecutionBackend> eb = std::make_shared<NaiveExecutionBackend>();

    std::shared_ptr<hamurai::Pipeline> p = std::make_shared<Pipeline>();
    p->setEventManager( eb );

    std::shared_ptr<hamurai::Kernel> k1 = std::make_shared< RandomNumberGenerator >();
    std::shared_ptr<hamurai::Kernel> k2 = std::make_shared< RandomNumberGenerator >();

    cerr << "kernel: " << k1 << endl;
    cerr << "kernel: " << k2 << endl;
    cerr << "pipeline: " << p << endl;
    cerr << "backend: " << eb << endl;

    p->addKernel( k1 );
    p->addKernel( k2 );

    eb->start();

    while(1)
    {
        p->start( eb );
        sleep(4);
        p->stop();
        sleep(1);
    }

    eb->join();

    return 0;
}
