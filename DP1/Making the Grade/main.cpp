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
long int a[2020];
long int b[2020];
int dp[2020][2020];
int main(void)
{
    int N;
    cin>>N;
    for(int i = 1 ;i <= N ;i++)
    {
        scanf("%ld",&a[i]);
        b[i] = a[i];
    }
    sort(b,b+N+1);
    for(int i = 1;i <= N;i++)
    {
        dp[1][i] = abs(a[1] - b[i]);
    }
    
    for(int i = 2 ;i <=  N;i++)
    {
        int minx = dp[i-1][1];//dp[i-1][0...j]的最小值

        for(int j = 1;j <= N;j++)
        {
            minx = min(minx ,dp[i-1][j]);
            dp[i][j] = minx + abs(a[i]-b[j]);

            
        }
    }
    cout<<*min_element(dp[N]+1,dp[N]+N+1)<<endl;
    return 0;
}

