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
int dp[21][801];
vector<int> path[21][801];
int main(void)
{
    int cnt = 1;//记录次数
    int s[201],pu[201];//两数相加pu[] 两数相减s[]
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < 801;j++)
            {
             path[i][j].clear();
            }
        }
        memset(dp,-1,sizeof(dp));
        int d,p;
        for(int i = 0;i < n;i++ )
        {
            cin>>d>>p;
            s[i] = d-p;
            pu[i] = d+p;
        }
        int fix = 20*m;//修正区间值
        dp[0][fix] = 0;//修正区间后 dp[0][fix]为原dp[0][0]
        for(int k = 0;k < n;k++)//选择一个
        {
            for(int i = m-1;i >= 0; i--)//从m开始逆推
            {
                for(int j = 0;j < 2*fix;j++)//辩控差
                {
                    if(dp[i][j] >= 0)
                    {
                        if(dp[i][j]+pu[k] >= dp[i+1][j+s[k]])//dp[i][j] 再选i+1人时 辩控和大于已知的时
                        {
                            dp[i+1][j+s[k]] = dp[i][j] + pu[k];
                            path[i+1][j+s[k]] = path[i][j];//更新路径
                            path[i+1][j+s[k]].push_back(k);
                        }
                        
                    }
                }
            }
            
        }
        printf("DP OK \n");
        int ans;
        printf("fix:%d\n",fix);
        for(ans = 0 ;dp[m][fix + ans]==-1&&dp[m][fix - ans]==-1;ans++);
        printf("ans :%d\n",ans);
        int temp = (dp[m][fix + ans] > dp[m][fix - ans])?ans:-ans;
        int sumd = (dp[m][fix + temp] + temp)/2;//d=(d+p+|d-p|)/2
        int sump = (dp[m][fix + temp] - temp)/2;//p=(d+p-|d-p|)/2
        printf("Jury #%d\n",cnt++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",sumd,sump);
        for( int i = 0 ;i < m ;i++ )
        {
            printf(" %d",path[m][fix + temp][i]+1);
        }
printf("\n\n");

    }
    return 0;
}

