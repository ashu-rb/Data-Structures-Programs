// CPP program to implement run length encoding
/*#include <bits/stdc++.h>
using namespace std;

void printRLE(string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {

	
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		// Print character and its count
		cout << str[i] << count;
	}
}

int main()
{
	string str = "wwwwaaadexxxxxxywww";
	printRLE(str);
	return 0;
}*/
#include<stdio.h> 
void merge(int a[],int b[],int x,int y)
{ 
int c[x+y],i=0,j=0,p=0; 
while((i<x) && (j<y))
{ 
if(a[i]<=b[j])
{ 
c[p++]=a[i++];
  
 } 
 else { 
 c[p++]=b[j++];
  } }
 while(i<x)
  { 
  c[p++]=a[i++];
  } 
   while(j<y)
   { 
   c[p++]=b[j++];
   }
  for(int k=0;k<p;k++)
	{ 
	printf("%d ",c[k]);
	} } 
	 
	main()
	{ 
	int A[]={1,6,7,9,18,21,23,26}; 
	int B[]={0,3,14,22,27,39}; 
	int m=sizeof(A)/sizeof(int);
	int n=sizeof(B)/sizeof(int);
	printf("DS LAB Assignment-1 C Program to Merge two Sorted Array By Aayush Patel 2K20/CO/11 \n \n"); 
	printf("Sorted Array A : \t"); 
	for(int l= 0;l<m;l++) 
	printf("%d ", A[l]);
	printf("\n");
	printf("Sorted Array B : \t"); 
	for(int l= 0;l<n;l++) 
	printf("%d ",B[l]);
	printf("\n \n"); 
	printf("Final sorted array, C after merging two sorted array A & B is: \n \n"); 
	merge(A,B,m,n); 
	
	}
