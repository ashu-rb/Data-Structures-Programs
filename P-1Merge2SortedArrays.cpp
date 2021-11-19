#include <stdio.h>
void merge(int a[], int b[], int x, int y)
{
	int c[x + y], i = 0, j = 0, p = 0;
	while ((i < x) && (j < y))
	{
		if (a[i] <= b[j])
		{
			c[p++] = a[i++];
		}
		else
		{
			c[p++] = b[j++];
		}
	}
	while (i < x)
	{
		c[p++] = a[i++];
	}
	while (j < y)
	{
		c[p++] = b[j++];
	}
	for (int k = 0; k < p; k++)
	{
		printf("%d ",c[k]);
	}
}

main()
{
	int A[] = {1, 6, 7, 9, 18, 21, 23, 26};
	int B[] = {0, 3, 14, 22, 27, 39};
	int m = sizeof(A)/sizeof(int),n = sizeof(B)/sizeof(int);
	printf("Sorted Array A : \t");
	for (int l = 0; l < m; l++)
	printf("%d ", A[l]);
	printf("\n");
	printf("Sorted Array B : \t");
	for (int l = 0; l < n; l++)
	printf("%d ",B[l]);
	printf("\n \n");
	printf("Final sorted array C, after merging two sorted array A & B is: \n \n");
	merge(A,B,m,n);
}
