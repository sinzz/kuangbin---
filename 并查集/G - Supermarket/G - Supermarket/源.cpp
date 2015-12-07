#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
typedef struct
{
	int p;
	int d;
}prod;
prod a[10010];
int comp(prod a, prod b)
{
	return a.d > b.d;

}
int main(void)
{
	int n;
	while (~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		int x  , y;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			a[i].p = x;
			a[i].d = y;
		}
		sort(a, a + n, comp);
		ll ans = 0;
		int tmax = 0;
		for (int i = 0; i < n; i++)
		{

		}
	}
	return 0;
}