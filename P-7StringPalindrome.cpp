#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 25

struct stack
{
    char a[MAX];
	int top;
};

void initstack(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, char b)
{
	s->top++;
    s->a[s->top] = b;
}

void pop(struct stack *s)
{
    s->top--;
}

int main()
{
    struct stack s;
    initstack(&s);
    char st[MAX];
    printf("Enter the string:");
    gets(st);
    int l = strlen(st);
    int m= l/2,i;
    if (l % 2 == 0)
    {
        for ( i = 0; i<m; i++)
        {
            push(&s, st[i]);
        }
        for ( i =m; i < l; i++)
        {
            if (st[i] == st[l - i - 1] )
            {
                pop(&s);
            }
            else
            {
                printf("Given string isn't palindrome\n");
                break;
            }
        }
        if (s.top == -1)
        {
            printf("Given string is palindrome\n");
        }
    }
   else
   {
        for ( i = 0; i <m; i++)
        {
            push(&s, st[i]);
        }
        for (i = m+ 1; i < l; i++)
        {
            if (st[i] == st[l - i - 1]  )
            {
                pop(&s);
            }
            else
            {
                printf("Given string isn't palindrome\n");
                break;
            }
        }
        if (s.top == -1)
        {
            printf("Given string is palindrome\n");
        }
    }
    return 0;
}