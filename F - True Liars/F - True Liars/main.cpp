/*************************************************************************
> File Name: main.cpp
> Author:Chazz
> Created Time: 2015年11月26日 星期四 18时20分52秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXN 650
int fa[MAXN];
int ra[MAXN];
int find(int x)
{
	if (fa[x] == -1) return x;
	int tmp = find(fa[x]);
	ra[x] += ra[fa[x]];
	ra[x] %= 2;
	return fa[x] = tmp;
}
void join(int x, int y, int r)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		fa[fx] = fy;
		ra[fx] = (ra[x] + ra[y] + r) % 2;
	}

}
typedef long long ll;
using namespace std;
int a[MAXN][2];
vector<int>b[MAXN][2];
int dp[MAXN][MAXN / 2];
int pre[MAXN][MAXN / 2];
bool used[MAXN];
int main(void){
	int n, p1, p2;
	while (scanf("%d%d%d", &n, &p1, &p2) != EOF && (n != 0 || p1 != 0 || p2 != 0))
	{
		memset(fa, -1, sizeof(fa));
		memset(ra, 0, sizeof(ra));
		int x, y;
		char s[5];
		while (n--)
		{
			scanf("%d%d%s", &x, &y, s);
			if (s[0] == 'y')
				join(x, y, 0);
			else
				join(x, y, 1);
		}
		for (int i = 0; i < MAXN; i++)
		{
			b[i][0].clear();
			b[i][1].clear();
			a[i][0] = 0;
			a[i][1] = 0;
		}
		memset(used, false, sizeof(used));
		int cnt = 1;
		for (int i = 1; i <= p1 + p2; i++)
		{
			if (!used[i])
			{
				int temp = find(i);
				for (int j = i; j <= p1 + p2; j++)
				{
					if (temp == find(j))
					{
						used[j] = true;
						b[cnt][ra[j]].push_back(j);
						a[cnt][ra[j]]++;
					}
				}
				cnt++;
			}


		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i < cnt; i++)
		{
			for (int j = p1; j >= 0; j--)
			{
				if (j - a[i][0] >= 0 && dp[i - 1][j - a[i][0]])
				{
					dp[i][j] += dp[i - 1][j - a[i][0]];
					pre[i][j] = j - a[i][0];

				}

				if (j - a[i][1] >= 0 && dp[i - 1][j - a[i][1]])
				{
					dp[i][j] += dp[i - 1][j - a[i][1]];
					pre[i][j] = j - a[i][1];
				}
			}
		}
		if (dp[cnt - 1][p1] != 1)
		{
			cout << "no" << endl;
		}
		else
		{
			vector<int>ans;
			ans.clear();
			int t = p1;
			for (int i = cnt - 1; i >= 1; i--)
			{
				int temp = t - pre[i][t];
				if (temp == a[i][0])
				{
					for (int j = 0; j < a[i][0]; j++)
					{
						ans.push_back(b[i][0][j]);
					}
				}
				else
				{
					for (int j = 0; j < a[i][1]; j++)
					{
						ans.push_back(b[i][1][j]);
					}
				}
				t = pre[i][t];
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << endl;
			}
			cout <<"end"<<endl;
		}

	}
	return 0;
}
