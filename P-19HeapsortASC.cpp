#include <stdio.h>
#define size 100
int a[size], n = 0;
void heapify (int a[], int n, int i)
{
    if (i >= n)
    return;
    int l = 2*i+1,r = 2*i+2;
    int id = i;
    if (l < n && a[l] > a[id])
    id = l;
    if (r < n && a[r] > a[id])
    id = r;
    if (i == id)
    return;
    if (i != id)
    {
        int tp = a[i];
        a[i] = a[id];
        a[id] = tp;
        i = id;
    }
    heapify (a, n, i);
}
void heap (int a[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify (a, n, i);
    }
}
void hsort(int a[], int n)
{
    heap (a, n);
    int sz = n;
    for (int i = 1; i <= n-1; i++)
    {
        int tp = a[0];
        a[0] = a[sz-1];
        a[sz-1] = tp;
        sz--;
        heapify (a, sz,0);
    }
}
int main ()
{
  
    printf("Enter size of array:");
    scanf("%d", &n);
    printf("Enter array elemnts:");
    for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);
    hsort (a, n);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
    return 0;
    }