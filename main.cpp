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
    cout << message << value << endl << endl;
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
}
template<typename TValue>
void get_value(TValue& value, bool indicator)
{
    cout << "Enter a character to find: ";
    cin >> value;

    cout << endl;
}

template<typename TReturn, typename TValue>
TReturn finder(TValue value, char symbol)
{
    unsigned long long counter{};

    unsigned long long i = 0;
    while (true)
    {
        if (value[i] == symbol)
        {
            counter++;
        }

        i++;

        if (value[i] == '\0')
        {
            break;
        }
    }

    return counter;
}

int main()
{
    char* value = new char[100];
    char symbol{};
    
    get_value<>(value);
    get_value<char>(symbol, true);

    unsigned long long counter = finder<unsigned long long, char*>(value, symbol);
    print<unsigned long long, const char*>(counter, "The symbol appears the following number of times: ");

    delete_value(value);

    char ch = _getch();
    return 0;
}