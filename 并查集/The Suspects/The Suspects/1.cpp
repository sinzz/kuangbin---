#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40000
int pre[N];
int cnt[N];
int rank[N] = { 0 };
void makeSet(int n)
{
	for (int i = 0; i < n; i++)
	{
		pre[i] = i;
		cnt[i] = 1;
	}
}
int find2(int x)
{
	if (pre[x] == x) return x;
	int rec[N], root, k = 0;
	for (; pre[x] != x; x = pre[x])
		rec[k++] = x;
	root = x;
	for (x = 0; x != k; x++)
		pre[rec[x]] = root;
	return root;
}
int find(int x)
{
	if (pre[x] != x)
		pre[x] = find(pre[x]);
	return pre[x];
}
void join(int x, int y)//³¬Ê±
{
	int fx = find2(x);
	int fy = find2(y);
	if (fx != fy)
	{
		pre[fx] = fy;
		cnt[fy] += cnt[fx];
	}

}
bool join2(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)return false;
	if (rank[fx] > rank[fy])
	{
		pre[fy] = fx;
		cnt[fx] += cnt[fy];
	}
	else{
		pre[fx] = fy;
		cnt[fy] += cnt[fx];
		if (rank[fx] == rank[fy])
			rank[fy]++;

	}
		
	
	return true;
}
int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m)  && (n || m))
	{
		makeSet(n);
		for (int i = 0; i != m; i++)
		{
			int t, f, c;
			scanf("%d%d", &t, &f);
			for (int j = 1; j != t; j++)
			{
				scanf("%d", &c);
// 				if (c == find(c))
// 
// 					join(c, f);
// 				else
// 					join(f, c);
				join2(f, c);
			}
		}
		printf("%d\n", cnt[find(0)]);
	}
}