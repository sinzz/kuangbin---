/*************************************************************************
	> File Name: main.cpp
	> Author:Chazz
	> Created Time: 2015年11月04日 星期三 15时42分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll dp[10][11][2];
int bit[10];
ll dfs(int pos ,int pre,int status,int limit){
    if(pos < 1){
        return !status;
    }
    if(!limit&&dp[pos][pre][status]!=-1){
        return dp[pos][pre][status];
    }
    int end = limit?bit[pos]:9;
    ll ans = 0;
    for(int i = 0;i <= end;i++){
            ans += dfs(pos -1 ,i,status||(pre == 6&&i ==2)||(i==4),limit&&i==end);
        //printf("pos:%dstatus:%di:%dans:%lld\n",pos,status,i,ans);
    }
    if(!limit){
        dp[pos][pre][status] = ans;
    }
    //printf("dp[%d][%d][%d] = %lld\n",pos,pre,status,ans);
    return ans;

}
ll solve(ll n){
    int len = 0;
    while(n){
        bit[++len] = n%10;
        n = n/10;
    }
    return dfs(len,0,0,1);
}
int main(void){
    ll n,m;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%lld%lld",&n,&m)&&n&&m){
        cout<<solve(m)-solve(n-1)<<endl;
    }
    return 0 ;
}

