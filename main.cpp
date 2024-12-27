#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    char value[] = "LOREM123465798ipsum!@#dolor$%^sit&*(AMET)";

    cout << "Input: " << endl << value << endl << endl;

    unsigned long long i = 0;
    while (true)
    {
        if (value[i] == '\0')
        {
            break;
        }

        if ((value[i] < 'a' || value[i] > 'z') && (value[i] < 'A' || value[i] > 'Z'))
        {
            value[i] = ' ';
        }

        i++;
    }

    unsigned long long words = 0;
    bool inWord = false;
    for (unsigned long long j = 0; j <= i; j++)
    {
        if (value[j] != ' ' && !inWord)
        {
            words++;
            inWord = true;
        }
        else if (value[j] == ' ')
        {
            inWord = false;
        }
    }

    cout << "Output: " << endl
        << "Words: " << words << endl
        << endl;

    char ch = _getch();
    return 0;
}
