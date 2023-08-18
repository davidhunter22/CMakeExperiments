import std;

void double_free( )
{
    auto* p = new int;

    delete p;
    delete p;
}

int main( )
{
    std::vector v;

    double_free( );

    return 0;
}
