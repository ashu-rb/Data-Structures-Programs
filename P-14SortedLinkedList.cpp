#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *nxt;
};

struct node *head = NULL;
void display()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("!Error:Empty List!\n");
        return;
    }
    printf("Display List:\n");
    while (ptr)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->nxt;
    }
    printf("\n");
}
void insertSorted()
{
    int x;
    printf("Enter value to inserted");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->nxt = NULL;
    if (!head)
    {
        head = ptr;
        return;
    }
    if (head->data >= x)
    {
        ptr->nxt = head;
        head = ptr;
        return;
    }
    if (head->data < x && head->nxt == NULL)
    {
        head->nxt = ptr;
        return;
    }
    struct node *p = head;
    struct node *tail = NULL;
    while (p && p->data < x)
    {
        tail = p;
        p = p->nxt;
    }
    if (!p)
    {
        tail->nxt = ptr;
        return;
    }
    tail->nxt = ptr;
    ptr->nxt = p;
}
void deleteNode()
{
    int x;
    printf("Enter value to Delete:");
    scanf("%d", &x);
    struct node *ptr = head;
    struct node *tail = NULL;
    if (head->data == x)
    {
        head = head->nxt;
        free(ptr);
    }
    while (ptr && ptr->data < x)
    {
        tail = ptr;
        ptr = ptr->nxt;
    }
    if (!ptr)
    {
        printf("Element not in list!\n");
        return;
    }
    if (ptr->data > x)
    {
        printf("Element not present in list!\n");
        return;
    }
    tail->nxt = ptr->nxt;
    free(ptr);
}
void search()
{
    int x;
    printf("Enter search value:");
    scanf("%d", &x);
    struct node *p = head;
    while (p)
    {
        if (p->data > x)
            break;
        if (p->data == x)
        {
            printf("Element found in list!\n");
            return;
        }
        p = p->nxt;
    }
    printf("Element not found!!\n");
}

int main()
{
    int choice, x;
    int y;
    struct node *start;
    start = NULL;
   while (1)
    {
        printf("\nChoose any operations:\n");
        printf("1.Insert new value.\n");
        printf("2.Delete from List\n");
        printf("3.Search value in Linked List\n");
        printf("4.Display List\n");
        printf("5.!Exit!\n");

        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 4:
            display();
            break;
        case 1:
            insertSorted();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            search();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Enter valid choice!\n");
            continue;
        }
    }

    return 0;
}
