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

template<typename TValue>
void delete_value(TValue*& value)
{
    delete[] value;
    value = nullptr;
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
TReturn get_value(TValue value, bool indicator)
{
    TReturn size = get_size<TReturn, const TValue>(value);
    TReturn input;

    cout << "Enter the character you want to insert: ";
    cin >> input;
    cout << endl;

    return input;
}
template<typename TReturn, typename TValue>
TReturn get_value(TValue value)
{
    TReturn size = get_size<TReturn, const TValue>(value);
    TReturn input;

    do
    {
        cout << "Enter the index of the character you want to insert: ";
        cin >> input;

        if (input < 0 || input >= size + 1)
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
void inserter(TValue& value)
{
    char symbol = get_value<char, TValue>(value, true);
    unsigned long long symbol_index = get_value<unsigned long long, TValue>(value);
    unsigned long long size = get_size<unsigned long long, const TValue>(value);

    char* new_value = new char[size + 2];

    for (unsigned long long i = 0; i < symbol_index; i++)
    {
        new_value[i] = value[i];
    }
    new_value[symbol_index] = symbol;
    for (unsigned long long i = symbol_index; i < size; i++)
    {
        new_value[i + 1] = value[i];
    }
    new_value[size + 1] = '\0';

    delete_value(value);
    value = new_value;
}

int main()
{
    char* value = new char[100] {"Hello world!"};

    print<const char*, const char*>(value, "Input:\nSentence: ");
    print<unsigned long long, const char*>(get_size<unsigned long long, const char*>(value), "Range: from 0 to ");
    cout << endl;
    inserter(value);
    print<const char*, const char*>(value, "Output: ");

    delete_value(value);

    char ch = _getch();
    return 0;
}