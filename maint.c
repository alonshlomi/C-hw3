#include<stdio.h>
#include "txtfind.h"

int main() 
{
    char word[WORD];
    char option[WORD];
    getWord(word);
    getWord(option);

    if(option[0] == 'a')
    {
        print_lines(word);
    } else if(option[0] == 'b') {
        print_similar_words(word);
    }
    return 0;
}