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
int n;
int dp[2020][2020];
int s[2020];
//dp[i][j] = max (dp[i-1][j]+s[i]*(n-j+i),dp[i][j-1]+s[i]*(n-j+i))
int main(void)
{
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j + i <=n;j++)
        {
            if(i==0&&j==0)
            {
                dp[i][j]=0;
              printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
            }
            else if(i==0&&j!=0)
            {
                dp[i][j] = max(dp[i][j],dp[i][j-1]+s[n-j+1]*(i+j));
              printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
            }
            else if(j==0&&i!=0)
            {
                dp[i][j] = max(dp[i-1][j]+s[i]*(i+j),dp[i][j]);
              printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
            }
            else
            {
              dp[i][j]=max(dp[i-1][j]+s[i]*(i+j),dp[i][j-1]+s[n-j+1]*(i+j));
              printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
            }

        }
    }
    int ans = -1;
    for(int i = 0 ;i <= n;i++)
    {
        for(int j = 0;j <= n; j++)
        ans = max(ans,dp[i][j]);
    }
    cout<<ans<<endl;

    return 0;
}

