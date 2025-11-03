#include "HelloWorld.h"

#include <fmt/format.h>
#include <fmt/os.h>

uint64_t foo()
{
    const char* data { "Hello world!" };

    auto s { fmt::format( "{}", 99 ) };

    auto e { fmt::vwindows_error( 3, "", {} ) };

    auto c = e.code( );
    auto w = e.what( );

    return s.size( );
}

//int main( )
//{
//    foo( );
//}