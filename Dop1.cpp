#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int combinatorics(int L, char *prefix, char *suffix, int m)
{
    int length = strlen(prefix) + strlen(suffix);
    if (L < length)
    {

            bool test = true;
            int count = 0;
            for (int i = strlen(prefix) - (length - L), k = 0; i < strlen(prefix), k < (length - L); k++, i++)
            {
                if (prefix[i] != suffix[k])
                {
                    test = false;
                }
            }
            if (test)
            {
                count++;
            }
            test = true;
            for (int i = strlen(suffix) - (length - L), k = 0; i < strlen(suffix), k < (length - L); k++, i++)
            {
                if (prefix[k] != suffix[i])
                {
                    test = false;
                }
            }
            if (test)
            {
                count++;
            }
            return count;
    }
    else if (L == length)
    {
        if (strcmp(prefix, suffix))
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (strcmp(prefix, suffix))
        {
            int difference = L - length;
            unsigned long long temp = pow(26, difference);
            return (2 * (temp % m));
        }
        else
        {
            int difference = L - length;
            unsigned long long temp = pow(26, difference);
            return (temp % m);
        }
    }
}

int main()
{
    cout << "Enter the number of tests: ";
    int t;
    cin >> t;
    for (int i = 1; i < t + 1; i++)
    {
        cout << "Test #" << i << ":" << endl;

        cout << "Enter the length of the original string and the divisor: ";
        int L, m;
        cin >> L >> m;

        char tmp[2];
        cin.getline(tmp, 2); // without this no prefix is entered

        char prefix[200], suffix[200];
        cout << "Enter the prefix string: ";
        cin.getline(prefix, 200);
        cout << "Enter the suffix string: ";
        cin.getline(suffix, 200);

        cout << "Solution is: " << combinatorics(L, prefix, suffix, m) << endl;
    }
    return 0;
}