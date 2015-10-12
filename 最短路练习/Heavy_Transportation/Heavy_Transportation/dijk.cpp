	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#define  MAXINT 1010
	#define  MAXD 9999999999
	#define min(a,b) (a<b?a:b)
	long int map[MAXINT][MAXINT];
	long int dist[MAXINT];
	void dijkstra(int n, int v)
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
			int tmp = 0;
			int u = v;
			for (int j = 1; j <= n; j++)
			if (!vis[j] && dist[j] > tmp)
			{
				u = j;
				tmp = dist[j];

			}
			vis[u] = 1;
			for (int j = 1; j <= n; j++)
			{
				if ((!vis[j]) && dist[j] < min(dist[u], map[u][j]))
					dist[j] = min(dist[u], map[u][j]);
			
			}

		}
	}
	int main() 
	{
		int t, c = 1;
		int n, m;
		int x, y, w;
		scanf("%d", &t);
		while (t--){
			memset(map, 0, sizeof(map));
			scanf("%d%d", &n, &m);	
			for (int i = 0; i < m; i++)
			{
				scanf("%d%d%d", &x, &y, &w);
			
					map[x][y] = w;
					map[y][x] = w;


			}
			dijkstra(n, 1);
			printf("Scenario #%d:\n%d\n", c++, dist[n]);
		}
		return 0;
	}