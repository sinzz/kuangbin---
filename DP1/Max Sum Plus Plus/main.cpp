#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
const int N = 1000005;
const int Max = -9999999999;
int a[N];//数组S
int b[N];//前J个最大和 带a[j]
int pre[N];//前J个最大 不带a[j]

using namespace std;

int main()
{

    long long int m,n;
    int summax;
   while(cin>>m>>n)
{
    b[0]=0;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=m;i++)
    {
        summax = Max;
        for(int j=i;j<=n;j++)
        {
            if(i==1)
                scanf("%d",&a[j]);
            b[j] = max(b[j-1],pre[j-1])+a[j];
            pre[j-1]=summax;
            summax = max(summax,b[j]);//循环到i++ j==j-1

        }

    }
    cout<<summax<<endl;
    }
    return 0;
}
