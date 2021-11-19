#include <stdio.h>
#include <stdlib.h>
void recmergesort(int f, int l, int a[], int b[])
{
	if (l <= f)   
	{
		return;
	}
	int m =l+(f-l)/ 2;
	recmergesort(f, m, a, b);
	recmergesort(m + 1, l, a, b);
	int x = f, y = m + 1;
	for (int i = f; i <= l; i++)
	{
		if (x == m + 1)
		{
			b[i] = a[y++];
		}
		else if (y == l + 1)
		{
			b[i] = a[x++];
		}
		else if (a[x] < a[y])
		{
			b[i] = a[x++];
		}
		else
		{
			b[i] = a[y++];
		}
	}
	for (int i = f; i <= l; i++)
	{
		a[i] = b[i];
	}
}

int main()
{
	int a[10], b[10], n;
	
	printf("Enter size of array :");
	scanf("%d", &n);
	printf("Enter array elements:\n");
	for (int i = 0; i < n; i++)
	scanf("%d", &a[i]);
	recmergesort(0, n - 1, a, b);
	printf("Final sorted array using Recursive Merge sort :\n");
	for (int i = 0; i < n; i++)
	printf("\t%d", a[i]);
	return 0;
}
