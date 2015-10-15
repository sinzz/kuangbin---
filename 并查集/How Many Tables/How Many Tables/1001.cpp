#include <stdio.h>
#include <stdlib.h>
#define  N 1010
int pre[N];
void makeSet(int n)
{
	for (int i = 0; i < n; i++)
		pre[i] = i;
}
int find(int x)
{
	if (pre[x] != x)
		pre[x] = find(pre[x]);
	return pre[x];
}
void join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a != b)
	{
		pre[a] = b;
	}
}
int main(void)
{
	int T, n, m;
	int x, y, sum;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		makeSet(n+1);
		for (int i = 1; i <=m; i++)
		{
			scanf("%d%d",&x,&y);
			join(x, y);
		}
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (find(i) == i)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}