#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 


int isValid(char *s)
{
    char *stack = malloc(sizeof(s));
    char *top;

    for(int i=0; i<strlen(s); i++)
    {
        if(*s == '{')
        {
            *stack = *s;
            stack++;
        }
        else if(*s == '}')
        {
            if(*top != '{')
                return 0;
            stack--;
        }
        else if(*s == '[')
        {
            *stack = *s;
            stack++;
        }
        else if(*s == ']')
        {
            if(*top != ']')
                return 0;
            stack--;
        }
        else if(*s == '(')
        {
            *stack = *s;
            stack++;
        }
        else if(*s == ')')
        {
            if(*top != ')')
                return 0;
            stack--;
        }
        top = stack;
        s +=i;
    }

    return 1;
}

int main(void)
{

    char *s = "[, ], {, }";

    printf("%d\n", isValid(s));
    return 0;
}