#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isExtension(string extension) 
{
    vector <string> extensions = {".re", ".exs", ".rb", ".py", ".sh", ".coffee", ".chpl", ".c", ".cpp", ".cs", ".java", ".kt", ".php",
                                  ".js", ".ts", ".erl", ".clj", ".d", ".go", ".R", ".swift", ".groovy", ".feature",".fun", ".t", ".plt"};
    for(string ext : extensions)
        if(ext == extension)
            return true;
    return false;
}

int startingIndex(string str)
{ 
    int index;
    if (str.find_last_of('/') < str.length())
    {
        index = str.find_last_of('/') + 1;
    }
    else
        index = 0;
    return index;
}

int endingIndex(string str)
{
    int index = str.length();
    string test[] = {"-test.", "_test.", "test.", "-tests.", "_tests.", "tests.", "-spec.", "_spec.", "spec.", "-step.", "_step.", "step.", "."};
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i = 0; i < 13; i++)
    {
        if(str.find(test[i]) < str.length())
        {
            index = str.find(test[i]);
            break;
        }
    }
    return index;
}

pair<int, int> filename(string str)
{
    int start, end;
    int pos = str.find_last_of('.');
    if(pos < str.length())
    {
        if(isExtension(str.substr(pos)))
        {
            start = startingIndex(str);
            end = endingIndex(str);
        } else {
            start = 0;
            end = str.length();
        }
    } else {
        start = 0;
        end = str.length();
    }
    return {start, end};
}

int main()
{
    assert(filename("haker").first == 0 && filename("haker").second == 5);
    assert(filename("haker.cpp").first == 0 && filename("haker.cpp").second == 5);
    assert(filename("HikerTest.js").first == 0 && filename("HikerTest.js").second == 5);
    assert(filename("Diamond_Spec.feature").first == 0 && filename("Diamond_Spec.feature").second == 7);
    assert(filename("fizz.buzz-tests.js").first == 0 && filename("fizz.buzz-tests.js").second == 9);
    assert(filename("test/FizzBuzz_test.exs").first == 5 && filename("test/FizzBuzz_test.exs").second == 13);
    assert(filename("haker.buzz").first == 0 && filename("haker.buzz").second == 10);
    return 0;
}