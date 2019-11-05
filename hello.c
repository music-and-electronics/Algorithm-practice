#include <stdio.h>
#include <stdlib.h>

void Allocation(int **array)
{
    int N;
    printf("N: ");
    scanf("%d",&N);
    srand((unsigned)time(NULL));
    array  =(int**)calloc(N,sizeof(int *));

    for(int i=0;i<N;i++)
    {
        array[i]=(int*)calloc(N,sizeof(int));
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i!=j) array[i][j] =(rand()%101);
            else     array[i][j] =0;
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    Caculation(array,N);

    for(int i=0;i<N;i++)
    {
        free(array[i]);
    }
    free(array);

}

void Caculation(int **array, int N)
{
    int minimum;
    int **matrix=(int**)calloc(N,sizeof(int*));
    for(int i=0;i<N;i++)
    {
        *matrix=(int*)calloc(N,sizeof(int));
    }

    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            matrix[i]=array[i][j]+array[j][i];
        }
    }

    free(matrix);

}
int main(void)
{
    int **array;
    Allocation(array);
}