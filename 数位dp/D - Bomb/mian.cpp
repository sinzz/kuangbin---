/*************************************************************************
	> File Name: mian.cpp
	> Author:Chazz 
	> Created Time: 2015年11月03日 星期二 18时47分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll dp[20][20][2];
int DIG[20];
// pos = 当前处理的位置（一般从高位到地位）
// pre = 上一个位的数字（更高的那一位）
// status = 要达到的状态 如果为1 则可以认为找了答案，到时候用来返回，
//          给计数器+1
//limit = 是否受限，也即当前处理这位能否随便取值。
ll dfs(int pos,int pre,int status,int limit){ 
    //如果搜索到尽头 返回是否找到了这个答案的状态
    if(pos < 1){
        return status ;
    }
    //DP里保存的时完整的，且不受限的答案，如果满足的话 可以直接返回
    if(!limit && dp[pos][pre][status]!=-1){
        return dp[pos][pre][status];
    }
    // 高位是否受限 返回结束标志
    int end = limit ?DIG[pos] : 9;
    ll ret = 0;
    //status 用||是因为如果前面找到答案那么后门还有没有答案就
    //无所谓了
    //limit 用&&是因为后面受限 必须由前面受限而且自身也受限推出
    for(int i = 0;i <=end ;i++){
        ret += dfs(pos -1 ,i ,status||(pre==4&&i ==9),limit && (i==end));
    }
    if(!limit){
        dp[pos][pre][status] = ret;
    }
    return ret;
}
ll solve(ll n){
    int len = 0;
    while(n){
        DIG[++len] = n % 10;
        n = n/10;
    }
  //  printf("len : %d\n",len);
  //  DIG[len+1] = 0;
    return dfs(len,0,0,1);
}
int main(void){
    int t;
    cin>>t;
    ll n;
    memset(dp,-1,sizeof(dp));
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0 ;
}

