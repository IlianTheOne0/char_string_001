#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void incorrect()
{
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Incorrect number" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

template<typename TValueL, typename TValueR>
void print(TValueL value, TValueR message)
{
    cout << message << value << endl;
}

template<typename TReturn, typename TValue>
TReturn get_size(TValue value)
{
    TReturn size = 0;

    while (value[size] != '\0')
    {
        size++;
    }

    return size;
}

template<typename TReturn, typename TValue>
TReturn get_value(TValue value)
{
    TReturn size = get_size<TReturn, const TValue>(value);
    TReturn input;

    cout << "Enter the character you want to delete: ";
    cin >> input;
    cout << endl;

    return input;
}
template<typename TReturn, typename TValue>
TReturn get_value()
{
    TReturn input;

    cout << "Enter the character you want to delete: ";
    cin >> input;
    cout << endl;

    return input;
}

template<typename TValue>
void inserter(TValue& value)
{
    char symbol = get_value<char, TValue>(value);
    unsigned long long size = get_size<unsigned long long, const TValue>(value);

    unsigned long long index = 0;
    for (unsigned long long i = 0; i < size; i++)
    {
        if (value[i] == symbol)
        {
            index++;
        }
        else
        {
            value[i - index] = value[i];
        }
    }

    value[size - index] = '\0';
}

int main()
{
    char value[] = "Hello world";

    print<const char*, const char*>(value, "Input:\nSentence: ");
    print<unsigned long long, const char*>(get_size<unsigned long long, const char*>(value), "Range: from 0 to ");
    cout << endl;
    inserter(value);
    print<const char*, const char*>(value, "Output: ");

    char ch = _getch();
    return 0;
}