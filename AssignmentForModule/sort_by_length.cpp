#include <iostream>
#include <fstream>

#include "sort_string_by_length.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        cout << '\n';
    }
    else
    {
        ifstream file;
        file.open(argv[1], ios::in);
        if(!file.is_open())
        {
            cerr << "sort: cannot read: " << argv[1] << " : No such file or directory ";
            exit(EXIT_FAILURE);
        }
        string line;
        vector<string> lines;
        while (file >> line) {
            lines.push_back(line);
            sortString(lines);
        }  
    }
    return 0;
}