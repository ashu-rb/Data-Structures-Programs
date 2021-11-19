#include <stdio.h>
#define sz 100
int a[sz], n=0;
void insert (int a[], int *n, int x)
{
    a[*n] = x;
    *n = *n+1;
    int i = (*n)-1;
    while (i > 0)
    {
        int p = (i-1)/2;
        if (a[i] < a[p])
        {
            int tp = a[i];
            a[i] = a[p];
            a[p] = tp;
            i = p;
        }
        else
        break;
    }
}
int Delete(int a[], int *n)
{
    int x = a[0];
    a[0] = a[*n-1];
    *n = *n-1;
    int i = 0;
    while (1)
    {
        int left = 2*i+1,right = 2*i+2,li = i;
        if (left < *n && a[left] < a[li])
        li = left;
        if (right < *n && a[right] < a[li])
        li = right;
        if (li == i)
        break;
        else
        {
            int tp = a[i];
            a[i] = a[li];
            a[li] = tp;
            i = li;
        }
    }
    return x;
}
void display(int a[], int *n)
{
    for(int i = 0; i < *n; i++)
    printf("%d ", a[i]);
}
int main ()
{
    
    int ch=0,x,y;
    while (ch!= 4)
    {
        printf("Menu options:\n");
        printf("1.insert\n");
        printf("2.Delete\n");
        printf("3.Display\nn");
        printf("4.!Exit!\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insert (a, &n, x);
            break;
            case 2:
            y = Delete (a, &n);
            printf("!Element deleted:%d!",y);
            break;
            case 3:
            display(a, &n);
            break;
            default:
            break;
        }
    }
}