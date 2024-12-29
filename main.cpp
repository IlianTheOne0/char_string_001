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

    do
    {
        cout << "Enter the index of the character you want to delete: ";
        cin >> input;

        if (input < 0 || input > size)
        {
            incorrect();
            continue;
        }
        cout << endl;
        break;
    } while (true);

    return input;
}

template<typename TValue>
void deleter(TValue& value)
{
    unsigned long long index = get_value<unsigned long long, TValue>(value);
    unsigned long long size = get_size<unsigned long long, const TValue>(value);

    for (unsigned long long i = index; i < size - 1; i++)
    {
        value[i] = value[i + 1];
    }

    value[size - 1] = '\0';
}

int main()
{
    char value[] = "Hello world!";

    print<const char*, const char*>(value, "Input:\nSentence: ");
    print<unsigned long long, const char*>(get_size<unsigned long long, const char*>(value), "Range: from 0 to ");
    cout << endl;
    deleter(value);
    print<const char*, const char*>(value, "Output: ");

    char ch = _getch();
    return 0;
}