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
        if ((value[i] < 'a' || value[i] > 'z') && (value[i] < 'A' || value[i] > 'Z'))
        {
            value[i] = ' ';
        }

        i++;

        if (value[i] == '\0')
        {
            break;
        }
    }

    i = 0;

    unsigned long long words = 0;
    bool inWord = false;
    while (true)
    {
        if (value[i] != ' ' && !inWord)
        {
            words++;
            inWord = true;
        }
        else if (value[i] == ' ')
        {
            inWord = false;
        }

        i++;

        if (value[i] == '\0')
        {
            break;
        }
    }

    cout << "Output: " << endl
        << "Words: " << words << endl
        << endl;

    char ch = _getch();
    return 0;
}
