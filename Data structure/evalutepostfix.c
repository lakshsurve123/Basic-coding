#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];

    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    for(int i=0; exp[i]!='\0'; i++)
    {
        char ch = exp[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int b = pop();
            int a = pop();

            switch(ch)
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}