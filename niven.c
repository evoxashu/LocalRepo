#include <stdio.h>
#include <stdbool.h>
int extract(int nn)
{
    int sum=0;
    while(nn!=0)
    {
        int d=nn%10;
        sum+=d;
        nn/=10;
    }
    return sum;
}
bool isNiven(int n)
{
    int s=extract(n);
    if(n%s==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    printf("Enter a number \n");
    scanf("%d",&n);
    int s=extract(n);
    if(isNiven(n))
    {
        printf("%d is a Niven number \n",n);
    }
    else
    {
        printf("%d is not a Niven number \n",n);
    }
    return 0;
}