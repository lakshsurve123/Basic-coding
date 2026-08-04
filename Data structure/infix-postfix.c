#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;

    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    if(x == '^')
        return 3;

    return -1;
}

int main()
{
    char exp[100];

    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    printf("Postfix Expression: ");

    for(int i=0; exp[i]!='\0'; i++)
    {
        char ch = exp[i];

        if(isalnum(ch))
        {
            printf("%c", ch);
        }

        else if(ch == '(')
        {
            push(ch);
        }

        else if(ch == ')')
        {
            while(stack[top] != '(')
                printf("%c", pop());

            pop();
        }

        else
        {
            while(top != -1 && priority(stack[top]) >= priority(ch))
                printf("%c", pop());

            push(ch);
        }
    }

    while(top != -1)
        printf("%c", pop());

    printf("\n");

    return 0;
}