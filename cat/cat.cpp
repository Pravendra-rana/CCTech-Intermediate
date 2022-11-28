#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        char c;
        while (1)
        {
            c = getchar();
            if (c == EOF)
                break;
            putchar(c);
        }
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *file;
            if (file = fopen(argv[i], "r"))
            {
                char c;
                while (1)
                {
                    c = getc(file);
                    if (c == EOF)
                        break;
                    cout << c;
                }
                fclose(file);
            }
            else
            {
                cout << "file doesn't exist";
            }
        }
    }
}