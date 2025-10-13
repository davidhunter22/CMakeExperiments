module;

export module ModuleExample;

export import :Partition1;
import :Partition2;

import std;

// https://github.com/MicrosoftDocs/cpp-docs/issues/4757
// https://stackoverflow.com/questions/52286991/what-is-the-expected-relation-of-c-modules-and-dynamic-linkage/74444920#74444920
export __declspec(dllexport) int MyFunc()
// export int MyFunc()
{
     int x = 10;
     // SomeFun( );

     // std::cout << "MyFunc( )" << std::endl;

     return x;
}

struct Zippy
{
    int zip_it( ) const;
};

// This gets treated as if  attached to the global module even when in the module purview
// https://gcc.gnu.org/onlinedocs/gcc-11.1.0/gcc/C_002b_002b-Modules.html
export extern "C++"
{
     __declspec(dllexport) int extern_cpp_fun( )
    {
        return 99;
    }
}