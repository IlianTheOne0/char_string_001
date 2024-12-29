#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

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

template<typename TValue>
void get_value(TValue* value)
{
    cout << "Enter a sentence (max 100 characters): ";
    cin.getline(value, 100);
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
    char* value = new char[100];
    get_value<>(value);

    unsigned long long letters = 0;
    unsigned long long digits = 0;
    unsigned long long symbols = 0;

    counter<unsigned long long, char*>(value, letters, digits, symbols);
    cout << endl << "Output: " << endl;
    print<unsigned long long, const char*>(letters, "\tLetters: ");
    print<unsigned long long, const char*>(digits, "\tDigits: ");
    print<unsigned long long, const char*>(symbols, "\tSymbols: ");

    delete_value(value);

    char ch = _getch();
    return 0;
}