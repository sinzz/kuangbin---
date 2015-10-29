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
typedef struct inode
{
    int start;
    int endt;
    int ef;
}node;
node m[1010];

int dp[1000100];
int N,M,R;
int comp(node a,node b)
{
    return a.start < b.start;
}
int main(void)
{
    int ans = 0;
    cin>>N>>M>>R;
    for(int i = 0;i < M ;i++)
    {
        scanf("%d%d%d",&m[i].start,&m[i].endt,&m[i].ef);
    }
    sort(m,m+M,comp);
    for(int i = 0 ;i < M ;i++)
    {
        dp[i] = m[i].ef;
        for(int j = 0;j < i;j++)
        {
            if(m[i].start>=(m[j].endt+R))
            {
                dp[i] = max (dp[i],dp[j]+m[i].ef);
            }

        }
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);

    return 0;
}

