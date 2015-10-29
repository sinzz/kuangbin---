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
int main(void)
{
    int t;
    int d[100000];
    int a[100000];
    int max;
    while(scanf("%d",&t)!=EOF)
    {
        max =1;
        for(int i = 0;i < t;i++)
        {
            scanf("%d",&a[i]);
            d[i]=1;
        }
        for(int i = 0;i < t ;i++)
        {
            for(int j = 0 ;j < i;j++)
            {
                if(a[i]>a[j]&&d[j]+1>d[i])
                    d[i]=d[j]+1;
            }
            if(max < d[i])
                max = d[i];
        }
        cout<<max<<endl;
    }
    return 0;
}

