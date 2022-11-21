#include <cassert>

using namespace std;

bool isPrimeNumber(int no){
    if(no <= 1)
      return false;
    else 
    {
        for(int i = 2; i < no/2 + 1; i++)
        {
            if(no % i == 0)
            return false;
        }
        return true;
    }
}

int main(void){
    assert(!isPrimeNumber(-1));
    assert(!isPrimeNumber(0));
    assert(!isPrimeNumber(1));
    assert(isPrimeNumber(2));
    assert(isPrimeNumber(3));
    assert(!isPrimeNumber(4));
    assert(isPrimeNumber(5));
    assert(!isPrimeNumber(12));
    assert(isPrimeNumber(17));
    return 0;
}