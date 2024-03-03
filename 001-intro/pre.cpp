#include <iostream>

// only add the logging message if the
// "directive" `DEBUG` is equal to 1.
#if DEBUG == 1
#define LOGGING(x) std::cout << x << std::endl;
#else
#define LOGGING(x)
#endif

// To pass the directive in build use:
// g++ pre.cpp -DDEBUG=1 -o pre && ./pre

int main()
{
    LOGGING("This is a logging message");
    return 0;
}
