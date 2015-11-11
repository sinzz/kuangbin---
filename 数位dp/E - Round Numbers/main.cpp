/*************************************************************************
> File Name: main.cpp
> Author:Chazz
> Created Time: 2015年11月10日 星期二 16时32分00秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int star, endb;
int digit[35];
int dp[35][35][35];
int dfs(int pos, int num0, int num1, bool limit,bool frist){
	if (pos < 1) {
		if (frist)
			return 1;
		if (num0 >= num1)
			return 1;
		return 0;
	}
	if (!limit&&dp[pos][num0][num1] != -1)
		return dp[pos][num0][num1];
	int enda = limit ? digit[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= enda; i++){
		if (frist){


			if (i){
				ans += dfs(pos - 1, num0, num1+1, limit&&i == enda, 0);
			}
			else{
				ans += dfs(pos - 1, 0, 0, limit&&i == enda, 1);
			}
		}
		else{
			if (i){
				ans += dfs(pos - 1, num0, num1 + 1, limit&&i == enda, 0);

			}
			else
			{
				ans += dfs(pos - 1, num0 + 1, num1, limit&&i == enda, 0);
			}
		}
	}
	if (!limit){
		dp[pos][num0][num1] = ans;
	}
	return ans;
}
int solve(int n){
	int len = 0;
	while (n){
		digit[++len] = n & 1;
		n >>= 1;
	}
	return dfs(len, 0, 0, 1,1);
}

int main(void){

	cin >> star >> endb;
	memset(dp, -1, sizeof(dp));
	
	cout << solve(endb) - solve(star - 1) << endl;

	return 0;
}
