#if defined(_WINDLL)
    #if defined(C_EXPORTS)
        #define C_EXPORT __declspec(dllexport)
    #else
        #define C_EXPORT __declspec(dllimport)
    #endif
#else
    #define C_EXPORT
#endif