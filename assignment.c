#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX INT_MAX

int count_no_setbits(int mask)
{
    int count =0;
    int n;
    while(mask)
    {
       n=mask%2;
       if(n==1)
            count++;
       mask=mask/2;
    }
    return count;
}
int min(int n,int m)
{
    if(m>n)
        return n;
    return m;
}
void main()
{
    int cost[3][3]={{3,2,7},{5,1,3},{2,7,2}};
    int dp[8];
    int job[3]={-1};
    for(int i=0;i<8;i++)
    {
        dp[i]=MAX;
        printf("%d\n",dp[i]);
    }
    dp[0]=0;
    for(int mask=0;mask<7;mask++)
    {
        int x=count_no_setbits(mask);
        for(int j=0;j<3;j++)
        {

            dp[mask|(1<<j)]=min(dp[mask|(1<<j)],(dp[mask]+cost[x][j]));
            if(dp[mask|(1<<j)]==dp[mask]+cost[x][j])
               job[j]=x;

        }
    }
        for(int i=0;i<3;i++)
    {
        printf("%d\n",job[i]);
    }
    printf("%d",dp[7]);

}
