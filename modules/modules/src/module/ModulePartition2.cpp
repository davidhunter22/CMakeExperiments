module ModuleExample:Partition2;

import std;

std::string  SomeFun( )
{
    char data[ 100 ];

    auto to_chars_result { std::to_chars( data, data + 100, 99.004334 ) };

    std::ostringstream os;

    os.setf( 10 );

    os << std::setw( 10 );

    return { data, to_chars_result.ptr };
}
