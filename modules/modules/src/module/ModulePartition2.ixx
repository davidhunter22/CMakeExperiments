module;

export module ModuleExample:Partition2;


import std;

export extern "C++" int adder( int x, int y )
{
    return x + y;
}

export __declspec(dllexport) std::string SomeFun();
export __declspec(dllexport) void SomeMoreFun();