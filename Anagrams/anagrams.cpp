#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void permutations(string s) 
{
    sort(s.begin(), s.end());
    cout << s << endl;
    while(next_permutation(s.begin(), s.end()))
        cout << s << endl;
}

int main() 
{
    string str;
    cout << "enter a string : ";
    cin >> str;
    permutations(str);
    return 0;
}