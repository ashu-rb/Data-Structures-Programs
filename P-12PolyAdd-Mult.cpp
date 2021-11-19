

#include <stdio.h>
#include <stdlib.h>
struct poly
{
    float coef;
    int exp;
};
void inpoly(struct poly poly[], int *sz)
{
    printf("\nEnter size of polynomial:");
    scanf("%d", sz);
    printf("Now enter Degree then coefficient of an element:\n");
    for (int i = 0; i < *sz; i++)
    {
        scanf("%d", &poly[i].exp);
        scanf("%f", &poly[i].coef);
    }
}
void outpoly(struct poly P1[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (P1[i].coef == 0)
            i++;
        else
            printf("(%.1f)", P1[i].coef);
        if (P1[i].exp == 0)
            printf("");
        else if (sz- i!= 1)
            printf("x^%d+", P1[i].exp);
        else
            printf("x^%d", P1[i].exp);
    }
}
void add(struct poly P1[], struct poly P2[], struct poly P3[], int s1, int s2, int *s3)
{
    int i = 0, j = 0, k = 0;
    *s3 = 0;
    while (i < s1 || j < s2)
    {

        if (P1[i].exp == P2[j].exp)
        {
            P3[k].coef = P1[i].coef + P2[j++].coef;
            P3[k++].exp = P1[i++].exp;
            (*s3)++;
            
        }
        else if (P1[i].exp > P2[j].exp)
        {
            P3[k].coef = P1[i].coef;
            P3[k++].exp = P1[i++].exp;
            (*s3)++;
           
        }
        else
        {
            P3[k].coef = P2[j].coef;
            P3[k++].exp = P2[j++].exp;
            (*s3)++;
            
        }
    }
}
void multiply(struct poly P1[], struct poly P2[], struct poly P3[], int s1, int s2, int *s3)
{
    struct poly P[100];
    int m = 0;
    for (int i = 0; i < 100; i++)
    {
        P3[i].coef = 0;P3[i].exp = 0;
        P[i].coef = 0;P[i].exp = 0;
    }
    for (int i = 0; i < s1; i++)
    {
        int k = -1, l = 0;
        for (l = 0; l < m; l++)
        {
            P[l].coef = P3[l].coef;
            P[l].exp = P3[l].exp;
        }
        for (int j = 0; j < s2; j++)
        {
            P3[++k].exp = P1[i].exp + P2[j].exp;
            P3[k].coef = P1[i].coef * P2[j].coef;
        }
        add(P3, P, P3, k + 1, l, &m);
    }

    *s3 = m;
}
int main()
{
    struct poly P1[10], P2[10], P3[100];
    int s1, s2, s3;
    inpoly(P1, &s1);
    inpoly(P2, &s2);
    add(P1, P2, P3, s1, s2, &s3);
    printf("\nAfter Addition of 2 Polynomials:\n");
    outpoly(P1, s1);
    printf("\t + \t");
    outpoly(P2, s2);
    printf("\n = \t");
    outpoly(P3, s3);
    multiply(P1, P2, P3, s1, s2, &s3);
    printf("\nAfter Multiplication of 2 Polynomials:\n");
    outpoly(P1, s1);
    printf("\t * \t");
    outpoly(P2,s2);
    printf("\n = \t");
    outpoly(P3, s3);
    return 0;
}
