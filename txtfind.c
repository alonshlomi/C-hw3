#include <stdio.h>
#include "txtfind.h"

int getLine(char s[])
{
    char ch;
    int num_count = 0;
    while (scanf("%c", &ch) == 1)
    {
        if (num_count == LINE)
            break;
        s[num_count] = ch;
        if (ch == '\n')
            break;
        num_count++;
    }
    return num_count;
}

int getWord(char w[])
{
    char ch;
    int num_count = 0;
    while (scanf("%c", &ch) > 0)
    {
        if (num_count == WORD)
            break;


        w[num_count] = ch;
        if ((ch == '\n') || (ch == '\t') || (ch == ' ') || (ch == 0))
            break;

        num_count++;
    }
    return num_count;
}

int substring(char *str1, char *str2)
{

    int j = 0;
    for (int i = 0; i < LINE; i++)
    {
        if (*(str1 + i) == *(str2 + j))
        {
            j++;
            if ((*(str2 + j) == 0) || (*(str2 + j) == ' ') || (*(str2 + j) == '\n'))
                return 1;
        }
        else
        {
            j = 0;
        }
        if (*(str1 + i) == '\n')
            break;
        if (*(str1 + i) == '\0')
            break;
    }

    return 0;
}

int similiar(char *s, char *t, int n)
{
    int letters = n;
    int i, j = 0;
    for (i = 0; i < LINE; i++)
    {
        if (s[i] == '\n')
            break;
        if (s[i] == 0)
            break;
        if (s[i] == ' ')
            break;
        if (s[i] == '\t')
            break;
        if (s[i] == t[j])
        {
            j++;
        }
        else
        {
            letters--;
        }
    }
    if (s[i] == '\n' || s[i] == 0 || s[i] == ' ' || s[i] == '\t')
    {
        if (t[j] == ' ' || t[j] == '\t' || t[j] == '\n' || t[j] == 0)
        {
            if (letters >= 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void print_lines(char *str)
{
    int n;
    char curr_line[LINE];
    getLine(curr_line);
    while ((n = getLine(curr_line)) > 0)
    {
        if (substring(curr_line, str) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", curr_line[i]);
            }
            printf("\n");
        }
    }
}

void print_similar_words(char *str)
{
    int n;
    char curr_word[WORD];
    getWord(curr_word);
    while ((n = getWord(curr_word)) > 0)
    {
        if (similiar(curr_word, str, 1) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", curr_word[i]);
            }
            printf("\n");
        }
    }
}