#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 330
typedef struct node
{
    int x,y,h,are;
}inode;
inode Node[N];
int cnt=1;
int dp[N];
bool comp(inode a,inode b)
{
    return a.are<b.are;

}

int main(void)
{
    int n;
    int len;
    int x,y,h;
    while(~scanf("%d",&n)>>n&&n)
    {
        len = 0;
        while(n--)
        {
            scanf("%d%d%d",&x,&y,&h);
           
                Node[len].x = x;
                Node[len].y = y;
                Node[len].h = h;
                Node[len].are = x*y;
                len++;
                Node[len].x = y;
                Node[len].y = h;
                Node[len].h = x;
                Node[len].are = y*h;
                len++;
                Node[len].x = x;
                Node[len].y = h;
                Node[len].h = y;
                Node[len].are = x*h;
                len++;
            
        }
        sort(Node,Node+len,comp);
        int MAX = 0;
       
        for(int i = 0;i < len; i++)
        {

            dp[i]=Node[i].h;
            for(int j = 0; j <  i; j++)
            if((Node[j].x < Node[i].x&&Node[j].y < Node[i].y)||(Node[j].y < Node[i].x&&Node[j].x < Node[i].y))
             {
                 dp[i]=max(dp[i],dp[j]+Node[i].h);
                 
             }
            MAX = max(dp[i],MAX);
        }
        printf("Case %d: maximum height = %d\n",cnt++,MAX);
    }

    return 0;
}	
