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
typedef struct inode{
    int x;
    int y;
    int h;
}node;
int maxl;
node m[1010];
int dp[1010][2];//dp[i][0]代表向左 dp[i][1]代表向右
void lefMintime(int i)
{
    int k = i -1 ;
    while(k > 0&&m[i].h - m[k].h <= maxl)//存在平台且高度合适
    {
        if(m[i].x >= m[k].x&&m[i].x <= m[k].y)//是否能落在平台上
        {
            dp[i][0] = m[i].h - m[k].h + min(dp[k][0] + m[i].x - m[k].x ,dp[k][1] + m[k].y - m[i].x);
            return;
        }
        else
        {
            k--;
        }
    }
        if(m[i].h - m[k].h>maxl)
        {
            dp[i][0] = 9000000;
        }
        else
        {
            dp[i][0] = m[i].h;
        }
}
void rightMintime(int i)
{
    int k = i - 1;
    while(k > 0&&m[i].h - m[k].h <= maxl)
    {
        if(m[i].y <= m[k].y&&m[k].x <= m[i].y)
        {
            dp[i][1] = m[i].h - m[k].h+ min(dp[k][0] + m[i].y - m[k].x,dp[k][1]+m[k].y - m[i].y);
            return;
        }
        else
        {
            k--;
        }
    }
        if(m[i].h-m[k].h > maxl)
        {
            dp[i][1] = 9000000;
        }
        else
        {
            dp[i][1] = m[i].h;   
        }
        
}
int findTime(int n)
{
    for(int i = 1 ;i <= n+1 ;i++)
    {
        lefMintime(i);
        rightMintime(i);
        //cout<<dp[i][0]<<"\n"<<dp[i][1]<<endl;
    }
    return min(dp[n+1][0],dp[n+1][0]);
}
int compa(node a,node b)
{
    return a.h <  b.h;
}
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        dp[0][1]=0;
        cin>>n>>x>>y>>maxl;
        m[0].x = -2000;
        m[0].y = 2000;
        m[0].h = 0;
        m[n+1].x = x;
        m[n+1].y = x;
        m[n+1].h = y;//初始化赋值
        for(int i = 1;i <= n ;i++)
        {
            scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].h);
        }
        sort(m,m+n+2,compa);
       // for(int i = 0;i < n+2 ;i++)
       // {
         //    printf("%d\n",m[i].h);
       // }
        printf("%d\n",findTime(n));

    }
    return 0;
}

