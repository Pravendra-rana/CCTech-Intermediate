#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 1)
        cout << "\n";
    else
    {
        for (int i = 1; i <= argc; i++)
            cout << argv[i] << " ";
        cout << "\n";
    }
    return 0;
}