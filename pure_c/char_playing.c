#include<stdio.h>

int main()
{
    char letter = 'a';
    printf("Letter \"a\": before bit shift %c %d\n",letter, letter);
    letter = letter >> 1;
    printf("Letter \"a\": after bit >> 1 shift %c %d\n",letter, letter);
    letter = letter << 1;
    printf("Letter \"a\": after bit << 1 shift %c %d\n",letter, letter);
    return 0;
}