#include <iostream>

using namespace std;

// ind 3 variant 14

int main()
{
    setlocale(LC_ALL,"ru");
    char array[80];
    cout << "Введите текст: " << endl;
    gets(array);

    int length = 0;
    for (length; array[length] != '\0'; length++);
    if (length>80) length = 80;

    cout << "Введенный текст длиной " << length << " символов:" << endl;
    for (int i = 0; i < length; i++)
        cout << array[i];
    
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if(array[i] == 35)
        {
            count++;
            array[i] = 0;
            array[i-count-(count-1)] = 0;
        }
        else count = 0;
    }

    cout << endl;
    for (int i = 0; i < length; i++)
        cout << array[i];
}