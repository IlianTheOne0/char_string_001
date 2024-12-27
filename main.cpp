#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char value[] = "abcdefghij ABCDEFGHIJ 1234567890 !@#$%^&*()";

    cout << "Input: " << endl << value << endl << endl;

    unsigned long long i = 0;

    unsigned long long letters = 0;
    unsigned long long digits = 0;
    unsigned long long symbols = 0;

    while (true)
    {
        if ((value[i] >= 'a' && value[i] <= 'z') || (value[i] >= 'A' && value[i] <= 'Z'))
        {
            letters++;
        }
        else if (value[i] >= '0' && value[i] <= '9')
        {
            digits++;
        }
        else if (value[i] != ' ')
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