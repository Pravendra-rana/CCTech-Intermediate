#include <iostream>
#include <algorithm>
#include <vector>

#include "sort_string_by_length.h"

using namespace std;

void sortString(vector<string> lines)
{
    sort(lines.begin(), lines.end());
    for (int j = 0; j < lines.size(); j++)
    cout << lines.at(j) << endl;
}