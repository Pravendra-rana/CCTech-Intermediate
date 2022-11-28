#include <cassert>
#include <limits>

using namespace std;

bool calculator(float num1, char op, float num2)
{
    switch (op)
    {
    case '+':
    {
        if ((numeric_limits<float>::max() - num2 < num1 && num2 > 0) || (numeric_limits<float>::min() - num2 > num1 && num2 < 0))
        {
            return false;
        }
        return true;
    }
    case '-':
    {
        if (numeric_limits<float>::min() + num2 > num1 && num2 > 0 || numeric_limits<float>::max() + num2 < num1 && num2 < 0)
        {
            return false;
        }
        return true;
    }
    case '*':
    {
        if (numeric_limits<float>::max() / num1 < num2 && num1 > 0 || (numeric_limits<float>::max() / num1 > num2 && (num1 < 0 && num2 < 0)) || (numeric_limits<float>::min() / num1 > num2 && num2 < 0) || (numeric_limits<float>::min() / num1 < num2 && num1 < 0))
        {
            return false;
        }
        return true;
    }
    case '/':
    {
        if (num2 == 0)
        {
            return false;
        }
        return true;
    }
    default :
        return false;
    }
}

int main()
{
    assert(!calculator(numeric_limits<float>::max(), '+', 1.0));
    assert(calculator(3.0, '+', 1.0));
    assert(!calculator(numeric_limits<float>::min(), '-', 1.0));
    assert(calculator(3.0, '-', 1.0));
    assert(!calculator(numeric_limits<float>::max(), '*', 2.0));
    assert(calculator(5.0, '*', -2.0));
    assert(!calculator(5.0, '/', 0));
    assert(calculator(5.0, '/', 2));
    return 0;
}