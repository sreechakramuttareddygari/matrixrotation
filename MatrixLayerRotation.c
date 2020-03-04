#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

// Complete the matrixRotation function below.
void matrixRotation(int matrix_rows, int matrix_columns, int** matrix, int r) {
int bmatrix[matrix_rows][matrix_columns];
int min;
if(matrix_columns<=matrix_rows)
min=matrix_columns;
else
min=matrix_rows;
for(int i=0;i<min/2;i++)
{ int n=2*(matrix_columns-2*i)+2*(matrix_rows-2*i)-4;
  int a[n];
  int j=0,k=i,l=i;
    while(k<matrix_columns-i)
      {a[j]=matrix[i][k++];
      j++;}
    l++;
    while(l<matrix_rows-i)
    {
        a[j]=matrix[l++][matrix_columns-i-1];
        j++;
    }

  k--;
  k--;
  while(k>=i)
  {
      a[j]=matrix[matrix_rows-i-1][k--];
      j++;
  }
  l--;
  l--;
  while(l>=i)
  {
      a[j]=matrix[l--][i];
      j++;
  }
  int rotate=r%n;
  int b[n];
  for(int m=0;m<n;m++)
  {if(m<n-rotate){
   b[m]=a[m+rotate];
  }
   else
   b[m]=a[rotate-(n-m)];
  }
  /*printf("\n");
  for(int m=0;m<n;m++)
  printf("%d ",b[m]);
  printf("\n");
  printf("\n");*/
  j=0;k=i;l=i;
    while(k<matrix_columns-i)
      {bmatrix[i][k++]=b[j];
      /* printf("%d %d %d %d\n",i,k-1,b[j],bmatrix[i][k-1]);*/
      j++;}
    /*   for(int i=0;i<matrix_rows;i++)
  {
      for(int j=0;j<matrix_columns;j++)
      {
          printf("%d ",bmatrix[i][j]);
      }
      printf("\n");}
      printf("\n");*/
    l++;
 /*   for(int m=i;m<k;m++)
    {
        printf("%d (%d)(%d)",bmatrix[i][m],i,m);
    }
    printf("\n");*/
    while(l<matrix_rows-i)
    {  /* printf("%d %d %d\n",l,matrix_columns-i-1,j);*/
        bmatrix[l++][matrix_columns-i-1]=b[j];
        j++;
    }
  /*   for(int i=0;i<matrix_rows;i++)
  {
      for(int j=0;j<matrix_columns;j++)
      {
          printf("%d ",bmatrix[i][j]);
      }
      printf("\n");}
      printf("\n");*/
/*   for(int m=i;m<l;m++)
    {
        printf("%d (%d)(%d)",bmatrix[m][matrix_columns-i-1],m,matrix_columns-i-1);
    }
    printf("\n");*/
  k--;
  k--;
  while(k>=i)
  {   /*printf("%d %d %d\n",matrix_rows-i-1,k,j);*/
      bmatrix[matrix_rows-i-1][k--]=b[j];
      j++;
  }
  /* for(int i=0;i<matrix_rows;i++)
  {
      for(int j=0;j<matrix_columns;j++)
      {
          printf("%d ",bmatrix[i][j]);
      }
      printf("\n");}
      printf("\n");*/
 /* for(int m=matrix_columns-i-1;m>=i;m--)
    {
        printf("%d (%d)(%d)",bmatrix[matrix_rows-i-1][m],matrix_rows-i-1,m);
    }
    printf("\n");*/
  l--;
  l--;
  while(l>i)
  {  /* printf("%d %d %d\n",l,i,j);*/
      bmatrix[l--][i]=b[j];
      j++;
  }
  /* for(int i=0;i<matrix_rows;i++)
  {
      for(int j=0;j<matrix_columns;j++)
      {
          printf("%d ",bmatrix[i][j]);
      }
      printf("\n");}
      printf("\n");*/
 /* for(int m=matrix_rows-i-1;m>=i;m--)
    {
        printf("%d (%d)(%d)",bmatrix[m][i],m,i);
    }
    printf("\n");*/
    if(i==0)
    printf("%d ",bmatrix[0][0]);
}

  for(int i=0;i<matrix_rows;i++)
  {
      for(int j=0;j<matrix_columns;j++)
      {   if(i!=0||j!=0)
          printf("%d ",bmatrix[i][j]);
      }
      printf("\n");
  }

}

int main()
{
    char** mnr = split_string(rtrim(readline()));

    char* m_endptr;
    char* m_str = mnr[0];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = mnr[1];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* r_endptr;
    char* r_str = mnr[2];
    int r = strtol(r_str, &r_endptr, 10);

    if (r_endptr == r_str || *r_endptr != '\0') { exit(EXIT_FAILURE); }

    int** matrix = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        *(matrix + i) = malloc(n * (sizeof(int)));

        char** matrix_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++) {
            char* matrix_item_endptr;
            char* matrix_item_str = *(matrix_item_temp + j);
            int matrix_item = strtol(matrix_item_str, &matrix_item_endptr, 10);

            if (matrix_item_endptr == matrix_item_str || *matrix_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(matrix + i) + j) = matrix_item;
        }
    }

    int matrix_rows = m;
    int matrix_columns = n;

    matrixRotation(matrix_rows, matrix_columns, matrix, r);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
