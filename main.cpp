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

template<typename TValue>
int size(TValue value)
{
    int size = 0;

    while (value[size] != '\0')
    {
        size++;
    }

    return size;
}

template<typename TValue>
bool is_palindrome(TValue value)
{
    int size_ = size<TValue>(value);
    int half_size = size_ / 2;

    bool state = true;

    for (int i = 0, j = size_ - 1; i < half_size; i++, j--)
    {
        if (value[i] == value[j])
        {
            state = true;
        }
        else
        {
            state = false;
            break;
        }
    }

    return state;
}

template<typename TValue>
void replacer(TValue& value)
{
    int size_ = size<TValue>(value);
    int index = 0;

    for (int i = 0; i < size_; i++)
    {
        if ((value[i] >= 'a' && value[i] <= 'z') || (value[i] >= 'A' && value[i] <= 'Z'))
        {
            value[index++] = value[i];
        }
    }

    value[index] = '\0';
}

template<typename TValue>
void algorithm(TValue value)
{
    print(value, "Input: ");
    replacer(value);
    print(is_palindrome(value), "Output: ");
    cout << endl;
}

int main()
{
    char value0[] = "abccba";
    algorithm(value0);

    char value1[] = "abc0cba!";
    algorithm(value1);

    char value2[] = "!@#ab#@!";
    algorithm(value2);

    char value3[] = "abcdefg!";
    algorithm(value3);

    char ch = _getch();
    return 0;
}
