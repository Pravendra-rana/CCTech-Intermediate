#include <math.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

double squareRoot(double number){
    try {
        errno = 0;
        double result = sqrt(number);
        if(errno != 0){
            throw strerror(errno);
        }
        return result;
    }
    catch(char* e){
        cout << e << endl;
        exit(errno);
    }
}

int main(){
    assert(squareRoot(-1) == 1);
    assert(abs(squareRoot(4) - 2) < 1e-9);
    assert(abs(squareRoot(0) - 0) < 1e-9);
    assert(abs(squareRoot(2) - 1.41421356237) < 1e-9);
    return 0;
}