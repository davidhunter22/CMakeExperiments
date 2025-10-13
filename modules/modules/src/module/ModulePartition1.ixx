module;

export module ModuleExample:Partition1;

import std;

export struct __declspec(dllexport) Foo
{
    int a;
    double b;

    std::string baz( );
};


struct NotExported
{
    int x;
};

