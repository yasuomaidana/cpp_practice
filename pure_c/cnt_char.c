#include <stdio.h>

int main(void)
{
    int blanks = 0, digits = 0, letters = 0, others = 0;
    int c;
    printf("C before asignment: %d",c);
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blanks;
        else if (c >= '0' && c <= '9')
            ++digits;
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            ++letters;
        else
            ++others;
    }
    printf(" blanks: %d \ndigits: %d\n letters: %d\nothers: %d", blanks, digits, letters, others);
}