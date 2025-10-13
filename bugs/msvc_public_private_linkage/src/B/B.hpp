#if defined(_WINDLL)
    #if defined(B_EXPORTS)
        #define B_EXPORT __declspec(dllexport)
    #else
        #define B_EXPORT __declspec(dllimport)
    #endif
#else
    #define B_EXPORT
#endif

B_EXPORT int b();