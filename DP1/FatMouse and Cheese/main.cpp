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
int dp[110][110];
int path[110][110];
int n,k;
int a[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//上下左右
int dfs(int x,int y)
{
    int maxl=0;
    if(!dp[x][y])
    {
        for(int i = 1 ;i <= k;i++)
        {
            for(int j = 0;j < 4;j++)
            {
                int xz = x+a[j][0]*i;
                int yz = y+a[j][1]*i;
                if(xz>=0&&xz<n&&yz>=0&&yz<n)
                {
                    if(path[xz][yz] > path[x][y])
                    {

                       int ans = dfs(xz ,yz);
                        maxl = max(ans,maxl);

                    }
                }
            }
            
        }
        dp[x][y] = maxl + path[x][y];
    }
    return dp[x][y];

    
}
int main(void)
{
    while(~scanf("%d%d",&n,&k)&&n!=-1&&k!=-1)
    {
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&path[i][j]);
        }
    }
    memset(dp,0,sizeof(dp));
    cout<<dfs(0,0)<<endl;
    }
    return 0;
}

