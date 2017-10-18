#include <iostream>

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

    virtual void onInit()
    {
        cerr << "Random Number Generator initialized !" << endl;
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
    p->addKernel( k1 );

    /*
    try{
        TestKernel k;
    }
    catch( hamurai::Exception& e )
    {
        cerr << e.verbose_what() << endl;
    }
    */

    return 0;
}
