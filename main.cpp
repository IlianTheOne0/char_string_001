#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char value[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    cout << "Input: " << endl << value << endl << endl;

    unsigned long long i = 0;
    while (true)
    {
        if (value[i] == ' ')
        {
            value[i] = '\t';
        }

        i++;

        if (value[i] == '\0')
        {
            break;
        }
    }

    cout << "Output: " << endl << value << endl << endl;

    char ch = _getch();
    return 0;
}