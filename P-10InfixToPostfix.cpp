#include <stdio.h>
#define sz 20
struct stack
{
  char a[sz];
  int top;
};
int icp(char ch)
{
  if (ch == '^')
    return 4;
  else if (ch == '*' || ch == '/' || ch == '%')
    return 3;
  else if (ch == '+' || ch == '-')
    return 2;
  else if (ch == '(')
    return 4;
  return -1;
}
int isp(char ch)
{
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/' || ch == '%')
    return 3;
  else if (ch == '+' || ch == '-')
    return 2;
  else if (ch == '(')
    return 1;
  else if (ch == '$')
    return 0;
  return -1;
}

int operandcheck(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 48 && ch <= 57))
    return 1;
  return 0;
}
int operatorr(char ch)
{
  if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    return 1;
  return 0;
}
int check(char infix[])
{
  struct brack
  {
    char para[sz];
    int t;
  };
  int i = 0;
  struct brack p;
  p.t = -1;
  while (infix[i] != '$')
  {
    if (operandcheck(infix[i]))
    {
      if (i == 0 || operatorr(infix[i - 1]))
      {
        i++;
      }
      else if (infix[i - 1] == '(')
        i++;
      else
      {
        return 0;
      }
    }
    else if (operatorr(infix[i]))
    {
      if (i == 0)
        return 0;
      else if (operatorr(infix[i - 1]))
        return 0;
      i++;
    }
    else
    {
      if (infix[i] == '(')
      {
        p.t = p.t + 1;
        p.para[p.t] = '(';
      }
      else if (infix[i] == ')')
      {
        if (p.t == -1)
          return 0;
        else
        {
          p.t = p.t - 1;
        }
      }
      else
        return 0;
      i++;
    }
  }
  if (p.t != -1)
    return 0;
  else
    return 1;
}
void push(struct stack *s, char ch)
{
  if (s->top == sz - 1)
    printf("!Error:Stack is Full!");
  else
  {
    s->top = s->top + 1;
    s->a[s->top] = ch;
  }
}
char pop(struct stack *s)
{
  char pc = s->a[s->top];
  s->top = s->top - 1;
  return pc;
}
int main()
{
  struct stack s;
  s.top = -1;
  char infix[sz],postfix[sz];
  printf("Enter Infix Expression(terminated with $)::");
  scanf("%s", infix);
  if (check(infix))
  {
    int i = 0, j = 0;
    while (infix[i] != '$')
    {
      char x = infix[i];
      if (operandcheck(x))
      {
        postfix[j++] = x;
      }
      else if (x == ')')
      {
        int y;
        while (s.a[s.top] != '(')
        {
          postfix[j++] = pop(&s);
        }
        y = pop(&s);
      }
      else if (operatorr(x))
      {
        while (isp(s.a[s.top]) >= icp(x))
        {
          postfix[j++] = pop(&s);
        }
        push(&s, x);
      }
      i++;
    }
    while (s.top >= 0)
    {
      postfix[j++] = pop(&s);
    }
    postfix[j++] = '$';
    postfix[j] = '\0';
    printf("Conversion of Infix to Postfix Expression::%s", postfix);
  }
  else
    printf("!Error:Wrong Infix Expression!");
  return 0;
}