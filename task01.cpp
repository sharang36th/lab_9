#include "header.h"
#include <cstring>  

// Задание 1
// Создает копию строки |str|.
char* CopyString(const char* str)
{
    if (str == nullptr)
    {
        return nullptr;
    }

    // считаем длину вручную 
    size_t len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    // +1 под '\0'
    char* out = new char[len + 1];

    // копируем память
    std::memcpy(out, str, len);

    out[len] = '\0';
    return out;
}


// Соединяет две строки в одну новую.
char* ConcatinateStrings(const char* a, const char* b)
{
    if (a == nullptr && b == nullptr)
    {
        return nullptr;
    }

    if (a == nullptr)
    {
        return CopyString(b);
    }

    if (b == nullptr)
    {
        return CopyString(a);
    }

    size_t lenA = 0;
    while (a[lenA] != '\0')
    {
        lenA++;
    }

    size_t lenB = 0;
    while (b[lenB] != '\0')
    {
        lenB++;
    }

    char* out = new char[lenA + lenB + 1];

    std::memcpy(out, a, lenA);
    std::memcpy(out + lenA, b, lenB);

    out[lenA + lenB] = '\0';
    return out;
}
