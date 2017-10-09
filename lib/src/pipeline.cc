
#include "pipeline.h"

std::vector< std::shared_ptr< hamurai::Kernel> > hamurai::Pipeline::kernels()
{
    std::vector< std::shared_ptr< hamurai::Kernel > > ret;
    for( auto kv : _nodes )
    {
        ret.push_back( kv.second );
    }
    return ret;
}

std::vector<std::shared_ptr<hamurai::Link> > hamurai::Pipeline::links()
{
    std::vector< std::shared_ptr< hamurai::Link > > ret;
    for( auto kv : _links )
    {
        ret.push_back( kv.second );
    }
    return ret;
}
