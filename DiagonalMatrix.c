#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the matrix:\n");
    scanf("%d",&n);
    int matrix [n][n];
    printf("Enter the elements in the matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d\t",&matrix[i][j]);
        }
    }
    int sum=0;
    printf("The original matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",matrix[i][j]);
            sum+=matrix[i][j];
        }
        printf("\n");
        
    }
    printf("The sum of the elements in the matrix is : %d\n",sum);
    printf("The diagonal matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                printf("%d\t",matrix[i][j]);
            }
            else
            {
                printf("\t");
            }
            }
            printf("\n");
        }
        return 0;
}