#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *nxt;
};
void insert(struct node **s, int x) //insert new node at beginning
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->value = x;
    p->nxt = NULL;
    if (*s == NULL)
    {
        *s = p;
    }
    else
    {
        p->nxt = *s;
        *s = p;
    }
}
void append(struct node **s, int x) //append at last
{
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->value = x;
    p->nxt = NULL;
    if (*s == NULL)
    {
        *s = p;
    }
    else
    {
        q = *s;
        while (q->nxt != NULL)
            q = q->nxt;
        q->nxt = p;
    }
}
void display(struct node *start) //display list
{
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf("%d \t", p->value);
        p = p->nxt;
    }
    printf("\n");
}
int search(struct node **start, int x) //search a node in list
{
    struct node *p;
    if (start == NULL)
        return 0;
    p = *start;
    while (p != NULL)
    {
        if (p->value == x)
            return (1);
        p = p->nxt;
    }
    return (0);
}
void insertafter(struct node **s, int x, int y)
{
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->value = y;
    p->nxt = NULL;
    if (*s == NULL)
    {
        *s = p;
        p->nxt = NULL;
    }
    else
    {
        q = *s;
        while (q->nxt != NULL && q->value != x)
        {
            q = q->nxt;
        }
        p->nxt = q->nxt;
        q->nxt = p;
    }
}
int delet(struct node **s, int x)
{
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    if (*s == NULL)
        return -1;
    p = NULL, q = *s;
    while (q != NULL && q->value != x)
    {
        p = q;
        q = q->nxt;
    }
    if (q != NULL)
    {
        if (p == NULL)
        {
            *s = q->nxt;
        }
        else
        {
            p->nxt = q->nxt;
        }
        delete (q);
    }
}

main()
{
    struct node *start;
    start = NULL;
    printf("Choose any operations:\n");
    int x, y, ch;
    while (1)
    {
        printf("1.Insert at beginning\n");
        printf("2.Append at end\n");
        printf("3.Insert x after y\n");
        printf("4.Delete x from list\n");
        printf("5.Display List\n");
        printf("6.Serach in list\n");
        printf("7.EXIT!\n");
        printf("Enter your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number to be inserted:");
            scanf("%d", &x);
            insert(&start, x);
            break;
        case 2:
            printf("Enter number to append:");
            scanf("%d", &x);
            append(&start, x);
            break;
        case 3:
            printf("Enter numbers x & y:");
            scanf("%d  %d", x, y);
            insertafter(&start, x, y);
            break;
        case 4:
            printf("Enter number to Delete:");
            scanf("%d", &x);
            delet(&start, x);
            break;
        case 5:
            printf("Display List:\n");
            display(start);
            break;
        case 6:
            printf("Enter number to serach:");
            scanf("%d", &x);
            if (search(&start, x) == 1)
            {
                printf("!%d element Found!\n", x);
            }
            else
            {
                printf("!%d Element not found!", x);
            }
            break;
        }
        if (ch == 7)
            break;
    }
}
