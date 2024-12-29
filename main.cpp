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
TReturn replacer(TValue value)
{
    TReturn i = 0;

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

    return i;
}

template<typename TReturn, typename TValue>
void counter(TValue value, TReturn& words, TReturn i)
{
    bool inWord = false;

    for (unsigned long long j = 0; j < i; j++)
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
}

int main()
{
    char value[] = "LOREM123465798ipsum!@#dolor$%^sit&*(AMET)";

    unsigned long long words = 0;
    unsigned long long i{};

    print<const char*, const char*>(value, "Input: ");
    i = replacer<unsigned long long, char*>(value);
    counter<unsigned long long, char*>(value, words, i);
    cout << endl << "Output: " << endl;
    print<unsigned long long, const char*>(words, "Words: ");

    char ch = _getch();
    return 0;
}
