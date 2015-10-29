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
const int N=1001;
using namespace std;
int dp[N];
int a[N];
int main(void)
{
    int n;
    int ans;
    while(~scanf("%d",&n)&&n)
    {
        ans =-9;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0;i < n;i++)
        {
            dp[i] = a[i];
            for(int j = 0;j < i;j++)
            if(a[i]>a[j])
                dp[i] = max(dp[i],dp[j]+a[i]);
            ans = max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

