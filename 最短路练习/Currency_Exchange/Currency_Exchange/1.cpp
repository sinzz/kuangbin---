#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAXINT 1100
#define MAXD 999999
struct edge{
	int u, v;
	double r, c;
}ed[MAXINT];
bool bellman_ford(int n, int v, double c, int e)
{
	double d[MAXINT];
	memset(d, 0, sizeof(d));

	d[v] = c;
	bool flag;
	for (int i = 1; i < n; i++)
	{
		flag = false;

		for (int j = 0; j < e; j++)
		if (d[ed[j].v] < (d[ed[j].u] - ed[j].c)*ed[j].r)
		{
			d[ed[j].v] = (d[ed[j].u] - ed[j].c)*ed[j].r;
			flag = true;

		}
		if (!flag)
			break;
	}
	for (int i = 0; i < e; i++)
	if (d[ed[i].v] < (d[ed[i].u] - ed[i].c)*ed[i].r)
		return true;

	return false;

}
int main(){
	int n, m, s;
	int x, y, e;
	double v, r1, c1, r2, c2;
	while (scanf("%d%d%d%lf", &n, &m, &s, &v) != EOF)
	{


		e = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%lf%lf%lf%lf", &x, &y, &r1, &c1, &r2, &c2);
			ed[e].u = x;
			ed[e].v = y;
			ed[e].r = r1;
			ed[e++].c = c1;
			ed[e].u = y;
			ed[e].v = x;
			ed[e].r = r2;
			ed[e++].c = c2;


		}
		if (bellman_ford(n, s, v, e))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}