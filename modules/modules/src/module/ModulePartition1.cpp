module;

module ModuleExample:Partition1;

import std;

std::string Foo::baz( )
{
    std::cout << "Foo::baz( )" << std::endl;
    return "Hello";
}
