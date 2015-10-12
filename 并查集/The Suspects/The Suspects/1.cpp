#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3030
int num, g, m;
int pre[N];
int vis[N];
int find(int x)
{
	int r = x;
	while (pre[r] != r)
		r = pre[r];
	return r;
}
void join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		pre[x] = y;
	}
	else if (fx == 0)
		pre[y] = 0;
}
int main(void)
{
	int k,f;
	int i = 0;
	int sum=1;
	scanf("%d%d", &num, &g);
	while (num != 0 && g != 0)
	{
		memset(pre, -1, sizeof(pre));
		memset(vis, 0, sizeof(vis));
		pre[0] = 0;
		while (g--)
		{
			scanf("%d%d", &m, &k);
			pre[k] = k;
			m--;
			while (m--)
			{
				scanf("%d", &f);
				join(f, k);
			}
			
		}
		while (i < num)
		{
			if (pre[i] != -1 && find(i) == 0)
				sum++;

		}
	}
}