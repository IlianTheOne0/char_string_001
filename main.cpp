#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

template<typename TValueL, typename TValueR>
void print(TValueL value, TValueR message)
{
    cout << message << endl << value << endl << endl;
}

template<typename TValue>
void replacer(TValue value)
{
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
}

int main()
{
    char value[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    print<const char*, const char*>(value, "Input: ");
    replacer<char*>(value);
    print<const char*, const char*>(value, "Output: ");

    char ch = _getch();
    return 0;
}