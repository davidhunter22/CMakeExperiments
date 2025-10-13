#if defined(_WINDLL)
    #if defined(A_EXPORTS)
        #define A_EXPORT __declspec(dllexport)
    #else
        #define A_EXPORT __declspec(dllimport)
    #endif
#else
    #define A_EXPORT
#endif

A_EXPORT int a( );