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
int DP[2020];
int a[2020];//一个人买的时间
int b[2020];//两个人一起买的时间
int main(void)
{
    int T;
    int k;
    int hh,mm,ss;
    cin>>T;
    while(T--)
    {
        cin>>k;
        for(int i = 1 ;i <= k;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 1 ;i < k ;i++)
        {
            scanf("%d",&b[i]);
        }
        DP[1]=a[1];
        for(int i = 2; i <= k ;i++)
        {
            DP[i]=min(DP[i-1]+a[i],DP[i-2]+b[i-1]);
        }
        hh = DP[k]/3600;
        mm = DP[k]%3600/60;
        ss = DP[k]%60;
        printf("%02d:%02d:%02d%s\n",(8+hh)%24,mm,ss,(hh+8)%24<12?" am":" pm");


    }
    return 0;
}

