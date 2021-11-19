
#include <stdio.h>
#include <string.h>
#define MAX 20
struct stack
{
    char a[MAX];
    int top;
};
void initstack(struct stack *s)
{
    s->top = -1;
}
void push(struct stack *s, char x)
{
    if (s->top == MAX - 1)
    {
        printf("!Error:Stack is Full!\n");
        return;
    }
    s->top++;
    s->a[s->top] = x;
}
void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("!Error:Stack is empty!\n");
    }
    s->top--;
}

int main()
{
    char str[MAX];
    struct stack s;
    initstack(&s);
    printf("Enter string:");
    gets(str);
    int l = strlen(str);
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '(')
        {
            push(&s,str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.top == -1)
            {
                printf("String isn't balanced\n");
                return 0;
            }
            else
            {
                pop(&s);
            }
        }
        continue;
    }
    
    if (s.top == -1)
    {
        printf("String is balanced\n");
    }
    return 0;
}
