#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

template<typename TValueL, typename TValueR>
void print(TValueL value, TValueR message)
{
    cout << message << value << endl;
}

template<typename TReturn, typename TValue>
void counter(TValue value, TReturn& letters, TReturn& digits, TReturn& symbols)
{
    unsigned long long i = 0;

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
}

int main()
{
    char value[] = "abcdefghij ABCDEFGHIJ 1234567890 !@#$%^&*()";

    unsigned long long letters = 0;
    unsigned long long digits = 0;
    unsigned long long symbols = 0;

    print<const char*, const char*>(value, "Input: ");
    counter<unsigned long long, char*>(value, letters, digits, symbols);
    cout << endl << "Output: " << endl;
    print<unsigned long long, const char*>(letters, "\tLetters: ");
    print<unsigned long long, const char*>(digits, "\tDigits: ");
    print<unsigned long long, const char*>(symbols, "\tSymbols: ");

    char ch = _getch();
    return 0;
}