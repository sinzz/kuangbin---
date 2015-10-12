#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXINT 9999999
#define MINNUM 1010
int map[MINNUM][MINNUM];
int dist[MINNUM];
void dijkstra(int n, int v)
{
	int s[MINNUM];
	for (int i = 1; i <=n; i++)
	{
		dist[i] = map[v][i];
		s[i] = 0;

	}
	dist[v] = 0;
	s[v] = 1;
	for (int i = 2; i <= n; i++)
	{
		int tmp = MAXINT;
		int u = v;
		for (int j = 1; j <= n; j++)
		if ((!s[j]) && dist[j] < tmp)
		{
			u = j;
			tmp = dist[j];
		}
		s[u] = 1;
		for (int j = 1; j <= n;j++)
		if ((!s[j]) && map[u][j] < MAXINT)
		{
			if (dist[u] + map[u][j] < dist[j])
				dist[j] = dist[u] + map[u][j];


		}
	}
}

int main(){
	int n, line;
	int a, b, c;
	while (scanf("%d%d", &line, &n) != EOF)
	{
		for (int  i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				map[i][j] = MAXINT;
		}
		for (int i = 0; i < line; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (map[a][b]>c)
			{
				map[a][b] = c;
				map[b][a] = c;
			}
		}
		dijkstra(n, 1);
		printf("Scenario #%d:\n%d\n",c++, dist[n]);

	}
	return 0;
}