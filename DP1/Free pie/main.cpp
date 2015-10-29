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
using namespace std;
int dp[100100][11];
int Max(int x,int y ,int z)
{
    int n;
    n=x>y?x:y;
    return n>z?n:z;
    
}
int main(void)
{
    int T;
    int x,y,max;
    while(~scanf("%d",&T)&&T)
    {
        max = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < T; i++)
        {
            scanf("%d%d",&x,&y);
            dp[y][x]+=1;
            if(y > max) 
                max = y;
        }
        for(int t =max -1;t >= 0;t--)
        {
            dp[t][0] +=Max(0,dp[t+1][0],dp[t+1][1]);
            for(int x = 1;x < 10;x++)
            {
                dp[t][x] += Max(dp[t+1][x-1],dp[t+1][x],dp[t+1][x+1]);

            }
            dp[t][10] += Max(dp[t+1][9],dp[t+1][10],0);

        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}

