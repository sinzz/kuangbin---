#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2000200;
int tree[maxn << 2];
void qmax(int rt)
{
	tree[rt] = max(tree[rt << 1], tree[(rt << 1) + 1]);

}
void build(int l, int r, int rt)
{
	if (l == r)
	{
		scanf("%d", &tree[rt]);
		return;
	}
	int m = (r + l) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, (rt << 1) + 1);
	qmax(rt);
}
void updata(int pos, int data, int l, int r, int rt)
{
	if (r == l)
	{
		tree[rt] = data;
		return;	
	}
	int m = (r + l) >> 1;
	if (pos <= m)
		updata(pos, data, l, m, rt << 1);
	else
		updata(pos, data, m + 1, r, (rt << 1) + 1);
	qmax(rt);

}
int query(int L, int R, int l, int r, int rt)
{
	if (L <= l&&R >= r)
	{
		return tree[rt];
	}
	int m = (r + l) >> 1;
	int ans = -1;
	if (L <= m)
		ans = max(ans, query(L, R, l, m, rt << 1));
	if (R > m)
		ans = max(ans, query(L, R, m + 1, r, (rt << 1) + 1));
	return ans;

}
int main(void)
{
	int n, m;
	while (~scanf("%d%d", &n, &m)){
		build(1, n, 1);
		for (int i = 0; i < m; i++)
		{
			char s;
			int x, y;
			cin >> s;
			scanf("%d%d", &x, &y);
			if (s == 'Q')
			{
				cout << query(x, y, 1, n, 1) << endl;

			}
			else
			{
				updata(x, y, 1, n, 1);
			}
		}
	}
	return 0;
}