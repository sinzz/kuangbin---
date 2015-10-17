#include <stdio.h>
#include <stdlib.h>
#define  N 50050
int ans;
int par[N];//父节点
int rel[N];//与父节点关系
void makeSet(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rel[i] = 0;
	}
}
int find(int x)
{
	int t;
	if (par[x] == x)
		return x;
	t = par[x];
	par[x] = find(par[x]);
	rel[x] = (rel[x] + rel[t]) % 3;
	return par[x];
}
void unoin(int x, int y, int d)
{
	int fx, fy;
	fx = find(x);
	fy = find(y);
	if (fx == fy)
	{
		if (d == 0 && rel[x] != rel[y])
			ans++;
		if (d == 1 && ((rel[y] + 3 - rel[x]) % 3) != 1)
			ans++;
	}
	else
	{
		par[fy] = fx;
		rel[fy] = ((3 - rel[y]) + d + rel[x]) % 3;

	}
}
int main(void)
{
	int n, k;
	int d, x, y;
	scanf("%d%d", &n, &k);
	makeSet(n);
	ans = 0;
	while (k--)
	{
		scanf("%d%d%d", &d, &x, &y);
		if (x > n || y > n)
			ans++;
		else if (d == 2 && x == y)
			ans++;
		else
			unoin(x - 1, y - 1, d - 1);

	}
	printf("%d\n", ans);
	return 0;
}