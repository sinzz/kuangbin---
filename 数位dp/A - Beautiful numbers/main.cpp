/*************************************************************************
	> File Name: main.cpp
	> Author:Chazz 
	> Created Time: 2015年11月04日 星期三 23时09分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
#define MOD 2520
typedef long long ll;
using namespace std;
ll dp[21][MOD+5][55];
int inde[MOD+5];
int bit[20];
void init(){
    int cnt = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i <= MOD;i++){
        if(MOD%i==0){
            inde[i] = cnt++;
        }
    }
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll dfs(int pos ,int presum,int prelcm,bool flag){
    if(pos < 1){
        return ( presum%prelcm == 0);
    }

    if(!flag && dp[pos][presum][inde[prelcm]]!=-1){
        return dp[pos][presum][inde[prelcm]];
    }
    int end = flag?bit[pos]:9;
    ll ans = 0;
    for(int i = 0;i <= end;i++){
        ans += dfs(pos-1,(presum*10+i)%MOD,i==0?prelcm:lcm(prelcm,i),flag&&i==end);
    }
    if(!flag){
        dp[pos][presum][inde[prelcm]] = ans;
    }
    return ans;
    
}
ll solve(ll n){
    int len = 0;
    while(n){
        bit[++len] = n%10;
        n = n/10;
    }
    return dfs(len ,0,1,1);
}
int main(void){
    int t;
    init();
    ll a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0 ;
    
}

