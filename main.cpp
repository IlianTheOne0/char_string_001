#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

template<typename TValueL, typename TValueR>
void print(TValueL value, TValueR message)
{
    cout << message << endl << value << endl << endl;
}

void incorrect()
{
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Incorrect sentence" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

template<typename TReturn, typename TValue>
TReturn get_size(TValue* value)
{
    TReturn size = 0;

    while (value[size] != '\0')
    {
        size++;
    }

    return size;
}

template<typename TValue>
void get_value(TValue* value)
{
    cout << "Enter a sentence (max 100 characters): ";
    cin.getline(value, 100);

    cout << endl;
}

template<typename TValue>
void replacer(TValue value)
{
    unsigned long long i = 0;
    while (true)
    {
        if (value[i] == '.')
        {
            value[i] = '!';
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

    print<const char*, const char*>(value, "Input: ");
    replacer<char*>(value);
    print<const char*, const char*>(value, "Output: ");

    char ch = _getch();
    return 0;
}