#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char value[] = "abcdefghij 1234567890 !@#$%^&*()";

    cout << "Input: " << endl << value << endl << endl;

    unsigned long long i = 0;

    unsigned long long letters = 0;
    unsigned long long digits = 0;
    unsigned long long symbols = 0;

    while (true)
    {
        if (int(value[i]) >= 97 && int(value[i]) <= 122)
        {
            letters++;
        }
        else if (int(value[i]) >= 48 && int(value[i]) <= 57)
        {
            digits++;
        }
        else if (int(value[i]) != 32)
        {
            symbols++;
        }

        i++;

        if (value[i] == '\0')
        {
            break;
        }
    }

    cout << "Output: " << endl
        << "Letters: " << letters << endl
        << "Digits: " << digits << endl
        << "Symbols: " << symbols << endl
        << endl;

    char ch = _getch();
    return 0;
}