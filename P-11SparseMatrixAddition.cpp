
#include <stdio.h>
#define sz 20
struct sparse
{
	int row,col,val;
};
typedef struct sparse smat;
void printmat(smat a[])
{
	
	int z = 1;
	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			if (z <= a[0].val)
			{
				if (i == a[z].row && j == a[z].col)
				{
					printf("%6d", a[z].val);
					z++;
				}
				else
				{
					printf("%6d", 0);
				}
			}
			else
			{
				printf("%6d", 0);
			}
		}
		printf("\n");
	}
}
void add(smat a[], smat b[], smat c[])
{
	int i = 1, j = 1,z = 1;
	while (i <= a[0].val || j <= b[0].val)
	{
		if (a[i].row < b[j].row)
		{
			c[z].row = a[i].row;
			c[z].col = a[i].col;
			c[z++].val = a[i++].val;
		}
		else if (b[j].row < a[i].row)
		{
			c[z].row = b[j].row;
			c[z].col = b[j].col;
			c[z++].val = b[j++].val;
		}
		else if (a[i].row == b[j].row && a[i].col < b[j].col)
		{
			c[z].row = a[i].row;
			c[z].col = a[i].col;
			c[z++].val = a[i++].val;
		}
		else if (a[i].row == b[j].row && b[j].col < a[i].col)
		{
			c[z].row = b[j].row;
			c[z].col = b[j].col;
			c[z++].val = b[j++].val;
		}
		else if (a[i].row == b[j].row && a[i].col == b[j].col)
		{
			c[z].row = a[i].row;
			c[z].col = a[i].col;
			c[z++].val = a[i++].val + b[j++].val;
		}
	}
	c[0].val = z;
}

int main()
{
	smat a[sz], b[sz],c[sz];
	//printf("DS LAB Assignment-11 sparse Matrix Addition by Aayush Patel 2x20/CO/11 \n");
	printf("Enter rows&cols for 1st,matrix:");
	scanf("%d %d", &a[0].row, &a[0].col);
	printf("Enter rows&cols for 2nd,matrix:");
	scanf("%d %d", &b[0].row, &b[0].col);
	if((a[0].row!=b[0].row) || (a[0].col!=b[0].col)) {
		printf("!Error:Can't Add these 2 Matrices!");
		return -1;
	}
	printf("Enter no. of non-zero elements,Matrix A:");
	scanf("%d", &a[0].val);
	printf("Enter matrix in sparse form:\n");
	for (int i = 1; i <= a[0].val; i++)
	{
		scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
	}
    printf("Enter no. of non-zero elements,Matrix B:");
	scanf("%d", &b[0].val);
	printf("Enter matrix in sparse form:\n");
	for (int i = 1; i <= b[0].val; i++)
	{
		scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].val);
	}
	printf("Matrix C, after addition of 2 matrices order(m*n form):");
	c[0].row=a[0].row;c[0].col=a[0].col;
	add(a,b,c);
	printf("\n+\n");
	printmat(a);
	printf("\n+\n");
	printmat(b);
	printf("\n=\n");
	printmat(c);
	return 0;
}
