#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXD 999999999.0
#define MAXNUM 220
#define max(a,b) (a>b?a:b)
typedef struct  
{
	int x;
	int y;

}Point;
Point p[MAXNUM];
double map[MAXNUM][MAXNUM];
double dist[MAXNUM];
double	GetDist(Point p1, Point p2){
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(x*x+y*y);
}
void dijkstra(int n, int v){
	int vis[MAXNUM];
	for (int i = 0; i < n; i++)
	{
		dist[i] = map[v][i];
		vis[i] = 0;
	}
	dist[v] = 0;
	vis[v] = 1;
	for (int i = 1; i < n; i++)
	{
		double tmp = MAXD;
		int u = v;
		for (int j = 0; j < n;j++)
		if ((!vis[j]) && dist[j] < tmp)
		{
			u = j;
			tmp = dist[j];

		}
		vis[u] = 1;
		for (int j = 0; j < n; j++)
		{
			if ((!vis[j]) && dist[j]>max(dist[u], map[u][j]))
				dist[j] = max(dist[u], map[u][j]);
		}
	}
}
int main(){
	int t,cnt=1;
	while (scanf("%d", &t) != EOF&&t != 0)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		for (int i = 0; i < t; i++)
		{

			for (int j = 0; j < i; j++)
			{
				map[i][j]=map[j][i]= GetDist(p[i], p[j]);
			}
			map[i][i] = 0;
		}
		dijkstra(t, 0);
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", cnt++, dist[1]);



	}
	return 0;
}