#include <iostream>
#include <cstring>

using namespace std;

// ind 1 variant 14

int main()
{
    char arr[80];
    gets(arr);
    cout << arr << endl;

    int currlen = 0, minimum = 100;
    int count = 0, mincount = 100;
    int n = strlen(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ')
        {
            if (currlen < minimum)
            {
                minimum = currlen;
                mincount = count + 1;
            }
            currlen = 0;
            count++;
        }
        else
            currlen++;
    }

    if (currlen < minimum)
    {
        minimum = currlen;
        mincount = count + 1;
    }

    cout << "min = " << minimum << endl;
    cout << "nomer slova = " << mincount << endl;
}