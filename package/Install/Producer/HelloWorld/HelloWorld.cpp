#include "HelloWorld.h"

#include <fmt/format.h>

uint64_t foo()
{
    const char* data { "Hello world!" };

    auto s { fmt::format( "{}", 99 ) };

    return s.size( );
}