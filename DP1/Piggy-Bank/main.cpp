/*************************************************************************
	> File Name: main.cpp
	> Author:Chazz
	> Mail: 292535961@qq,com
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#define N 100005
#define INF 10000000
int dp[N];
int p[N];
int w[N];
using namespace std;
int main(void)
{
    int T;
    int a,b,tal;
    int n;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&a,&b);
        tal = b - a;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&p[i],&w[i]);
        }
        dp[0]=0;
        for(int i = 1; i <= tal; i++)
            dp[i]=INF;
        for(int i = 1; i <= n; i++)
            for(int j = w[i]; j <= tal; j++)
        {
            dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
        }
        if(dp[tal]==INF)
            printf("This is impossible.\n");
        else
	    printf("The minimum amount of money in the piggy-bank is %d.\n",dp[tal]);
            
    }
    return 0;
}

