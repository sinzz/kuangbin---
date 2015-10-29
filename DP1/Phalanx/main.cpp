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
int dp[1010][1010];
char s1[1010][1010];
int n;
int func()
{
    int ans = 1;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
           if(i==0&j==n-1)
            {
                dp[i][j] = 1;
                continue;
            }
            int l = i,r = j;
            while(l >= 0&&r <n&&s1[l][j]==s1[i][r])
            {
                l--;
                r++;

            }
            l = i- l;
            if(l >=dp[i-1][j+1]+1)
            {
                dp[i][j] = dp[i-1][j+1]+1;
            }
            else
            {
                dp[i][j] = l;
            }
            ans = max(ans,dp[i][j]);
        }

    }
    return ans;
    

}
int main(void)
{
    while(~scanf("%d",&n)&&n)
    {	memset(dp,0,sizeof(dp));
        for(int i = 0;i < n;i++)
        {
                cin>>s1[i];
        }
        cout<<func()<<endl;

    }

    return 0;
}

