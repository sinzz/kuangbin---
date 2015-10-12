#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXINT 1010
#define MAXD 999999999
long int map1[MAXINT][MAXINT];
long int map2[MAXINT][MAXINT];
long int dist1[MAXINT];
long int dist2[MAXINT];
void dijkstra(int n, int v, long int dist[], long int map[MAXINT][MAXINT])
{
	int vis[MAXINT];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = map[v][i];
		vis[i] = 0;

	}
	dist[v] = 0;
	vis[v] = 1;
	for (int i = 2; i <= n; i++)
	{
		long int tmp = MAXD;
		int u = v;
		for (int j = 1; j <= n; j++ )
		{
			if ((!vis[j]) && dist[j] < tmp)
			{
				u = j;
				tmp = dist[j];
			}
		}
		vis[u] = 1;
		for (int j = 1; j <= n; j++)
		{
			if ((!vis[j]) && map[u][j]<MAXD)
			if (dist[j]>dist[u] + map[u][j])
				dist[j] = dist[u] + map[u][j];

		}
	}
}
int main()
{
	int n, m, x;
	int a, b, w;
	long int sum=0;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n;i++)
	for (int j = 1; j <= n; j++)
	{
		map1[i][j] = MAXD;
		map2[j][i] = MAXD;
	}
	for (int i = 0; i < m; i++)
	{  
		scanf("%d%d%d", &a, &b, &w);
		map1[a][b] = w;
		map2[b][a] = w;
	}
	dijkstra(n,x,dist1,map1);
	dijkstra(n,x,dist2,map2);
	for (int i = 1; i <= n;i++)
	if (sum < dist1[i] + dist2[i])
		sum = dist1[i] + dist2[i];
	printf("%ld",sum);
	return 0;
}