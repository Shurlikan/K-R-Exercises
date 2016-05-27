/* Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tabs stop, say
every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define MAXLINE     1000
#define TABWIDTH    5

int get_text(char input[]);
void detab();
void spaces(int times);

int main()
{
    char input[MAXLINE];
    int lenght;

    lenght = get_text(input);
    detab(input, lenght);

    return 0;
}

void detab(char input[], int lenght)
{
    int i;
    int line_position = 0;

    for(i=0; i<lenght; ++i)
    {
        if(input[i] == '\n')
        {
            putchar(input[i]);
            line_position = 0;
        }
        else if(input[i] == '\t')
           spaces(TABWIDTH - (line_position % TABWIDTH));
        else {
            putchar(input[i]);
            ++line_position;
        }
    }
}

int get_text(char input[])
{
    int i, c;
    for(i=0; i<MAXLINE-1 && (c = getchar()) != EOF; ++i)
       input[i] = c;
    return i;
}

void spaces(int times)
{
    int i;

    for(i=0; i<times; ++i)
        putchar(' ');
}
