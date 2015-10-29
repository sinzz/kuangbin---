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
char a[1010];
char b[1010];
int dp[1010][1010];
using namespace std;
int main(void)
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        int lena = strlen(a);
        int lenb = strlen(b);
        for(int i = 0;i < lena+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0;j < lenb+1;j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1;i < lena+1;i++)
            for(int j = 1;j < lenb+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        cout<<dp[lena][lenb]<<endl;
    }
    return 0;
}

