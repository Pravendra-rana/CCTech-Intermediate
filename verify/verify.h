#ifndef VERIFY_H
#define VERIFY_H 1

#define verify(condition) \
    do\
    {\
        if (!(condition))\
        {\
        cerr << __FILE__ << ":" << __LINE__ << ": error: In function " \
             << __func__ << ", verification of condition " << #condition <<" failed.";\
        }\
    } while (0)
#endif