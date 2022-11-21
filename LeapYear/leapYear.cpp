#include <assert.h>
#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    assert(!isLeapYear(2001));
    assert(!isLeapYear(2002));
    assert(isLeapYear(2004));
    assert(!isLeapYear(2006));
    assert(isLeapYear(2008));
    assert(!isLeapYear(2100));
    assert(!isLeapYear(2200));
    assert(isLeapYear(2400));
    assert(isLeapYear(2800));
    return 0;
}