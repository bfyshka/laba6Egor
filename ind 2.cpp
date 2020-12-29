#include <iostream>
#include <cstring>

using namespace std;

// ind 2 variant 15

bool letter(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


int main()
{
    char text[10000];
    cin.getline(text, 10000);
    int n = strlen(text);
    char words[100][100];
    int words_size = 0;

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || !letter(text[i - 1])) && letter(text[i]))
        {
            char word[60];
            for (int j=0; j<60; j++) word[j] = 0;
            int word_size = 0;

            for (; i < n; i++)
            {
                word[word_size++] = text[i];
                if (i == n - 1 || !letter(text[i + 1]))
                {
                    break;
                }
            }

            if (word[0] == word[word_size - 1])
            {
                for (int j=0; j<word_size; j++)
                {
                    words[words_size][j] = word[j];
                }
                words_size++;
            }
        }
    }

    char *answer[10000];
    int answer_size = 0;

    for (int i = 0; i < words_size; i++)
    {
        bool tmp = true;
        for (int j = 0; j < answer_size; j++)
        {
            if (!strcmp(words[i], answer[j]))
            {
                tmp = false;
                break;
            }
        }
        if (tmp) answer[answer_size++] = words[i];
    }

    if (answer_size == 0) cout << "The are no words with equal first and last letters.";
    else cout << "There are " << answer_size << " unique word(s) with equal first and last letters: " << endl;

    for (int i = 0; i < answer_size; i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
