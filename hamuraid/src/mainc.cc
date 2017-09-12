#include <iostream>

#include <hamurai.h>

using namespace std;
using namespace hamurai;

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

        Event e;
        while( queryEvent( e, -1 ) )
        {
            cerr << "event !" << endl;
            if( e.type() == Event::HAMURAI_EVENT_DATA )
            {
                cerr << "data...." << endl;
            }
        }
    }
};

int main( int argc, char** argv )
{
    try{
        TestKernel k;
    }
    catch( hamurai::Exception& e )
    {
        cerr << e.verbose_what() << endl;
    }

    return 0;
}
