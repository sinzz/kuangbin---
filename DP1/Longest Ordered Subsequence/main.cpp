/*************************************************************************
	> File Name: main.cpp
	> Author:Chazz
	> Mail: 292535961@qq,com
 ************************************************************************/
//WA两次 忘写max

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int a[1010];
int dp[1010];
int main(void)
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }
    int maxl=0;
    for(int i = 0;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i = 1;i<=n ;i++)
    {
        for(int j =1;j<=i;j++)
        {
            if(a[i]>a[j]&&dp[j]+1>dp[i])
            dp[i]=dp[j]+1;
        }
        maxl=max(maxl,dp[i]);
    }
    cout<<maxl<<endl;
    return 0;
}

