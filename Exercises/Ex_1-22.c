/******************************************************************************

Author: Lorenzo Antenucci
Date: 05/26/2016
File: Ex_1.22.c

Description: Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column.

*******************************************************************************/
#include <stdio.h>

#define MAXLINE     10000
#define n           10

void fold(char input[], int lenght);
int get_line22(char input[]);

char input[MAXLINE];
int lenght;

int main()
{
    lenght = get_line22(input);
    fold(input, lenght);
    return 0;
}

void fold(char input[], int lenght)
{
    int i, j;

    for(i=0; i<lenght; ++i)
    {
        if(i % n == 0)
        {
            printf("\n");
            putchar(input[i]);
        }
        else
            putchar(input[i]);
    }
}

int get_line22(char input[])
{
    int i, c;
    for(i=0; i<MAXLINE-1 && (c = getchar()) != EOF; ++i)
        input[i] = c;
    return i;
}
