#include "functions.c"
int main()
{
     char str[3];
     scanf("%s", str);
     if (/*str[0] == 'T' && str[1] == 'R' && */str[2] == 'A')
     {
          int rows, cols, nz;
          scanf("%d %d %d", &rows, &cols, &nz);
          int **a = (int **)malloc(sizeof(int *) * 3);
          int i=0;
          while (i < 3)
          {
               a[i] = (int *)malloc(sizeof(int) * nz);
               i++;
          }
          int j=0;
          while ( j < nz )
          {
               scanf("%d", &a[0][j]);
               scanf("%d", &a[1][j]);
               scanf("%d", &a[2][j]);
               j++;
          }
          sort(nz,a);
          printf("%d\n", nz);
          int k=0;
          while (k < nz)
          {
               printf("%d ", a[1][k]);
               printf("%d ", a[0][k]);
               printf("%d ", a[2][k]);
               printf("\n");
               k++;
          }
     }
}