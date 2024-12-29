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

template<typename TReturn, typename TValue>
TReturn size(TValue value)
{
    TReturn size = 0;

    while (value[size] != '\0')
    {
        size++;
    }

    return size;
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
    unsigned long long size{};

    print<const char*, const char*>(value, "Input: ");
    size = size<unsinged long long, char*>(value);
    print<const char*, const char*>(value, "Output: ");

    char ch = _getch();
    return 0;
}