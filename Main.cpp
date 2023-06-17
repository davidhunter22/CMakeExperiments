
void double_free( )
{
    auto* p = new int;

    delete p;
    delete p;
}

int main( )
{
    double_free( );

    return 0;
}
