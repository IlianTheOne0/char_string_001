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
    cout << message << endl << value << endl << endl;
}

template<typename TReturn, typename TValue>
TReturn _size(TValue value)
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
    TReturn size = _size<TReturn, const char*>(value);
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
        break;
    } while (true);

    return input;
}

template<typename TValue>
void replacer(TValue value)
{
    unsigned long long index = get_value<unsigned long long, char*>(value);
    unsigned long long i = 0;
 
    
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