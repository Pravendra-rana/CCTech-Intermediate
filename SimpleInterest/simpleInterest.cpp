#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

class SimpleInterest {
public:
    int year;
    float intRate, principle;
    float getSimpleInterest(int t, float i, float p){
        year = t;
        intRate = i;
        principle = p;
        return (float)(principle * intRate * year)/100;
    }
};

int main(){
    SimpleInterest s;
    assert(s.getSimpleInterest(1, 4.5, 10000) != 45);
    assert(s.getSimpleInterest(1, 4.5, 10000) == 450);
    assert(s.getSimpleInterest(2, 4.5, 10000) == 900);
    return EXIT_SUCCESS;
}