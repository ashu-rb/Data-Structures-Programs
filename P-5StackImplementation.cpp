
#include <stdio.h>
#define max 25
struct stack
{
	int a[max], top;
};
void initstack(struct stack *s)
{
	s->top = -1;
}
void push(struct stack *s, int b)
{
	if (s->top == max - 1)
	{
		printf("!Error:Stack is Full:Overflow!\n");
		return;
	}
	s->top++;
	s->a[s->top]=b;
	return;
}
int pop(struct stack *s)
{
	int b;
	if (s->top == -1)
	{
		printf("!Error:Empty Stack!\n");
		return 0;
	}
	b = s->a[s->top--];
	return(b);
}
void display(struct stack s)
{
	for (int i = s.top; i >= 0; i--)
	{
		printf("%d\t",s.a[i]);
	}
	printf("\n");
}
main()
{
	int option, b;
	struct stack s;
	initstack(&s);
	do
	{
		printf("Stack Operations:\n");
		printf("1.Push Element\n");
		printf("2.Pop Element\n");
		printf("3.Display Stack\n");
		printf("4.!Exit!\n");
		printf("Enter your option:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("Enter element to be pushed in stack:");
			scanf("%d", &b);
			push(&s, b);
			printf("Element Pushed.\n");
			break;
		case 2:
			b = pop(&s);
			if (b != -1)
			printf("%d is Deleted\n", b);
			break;
		case 3:
			printf("Stack elements are:\n");
			display(s);
			break;
		default:
			printf("!Exit!");
			break;
		}
	} while (option != 4);
}
