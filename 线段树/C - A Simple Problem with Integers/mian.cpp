#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 100100;
long long sum[maxn << 2];
long long  addmark[maxn << 2];
void pushup(int root)
{
	sum[root] = sum[root << 1] + sum[root << 1 | 1];

}
void pushdown(int root,int m)
{
	if (addmark[root])
	{
		addmark[root << 1] += addmark[root];
		addmark[root << 1 | 1] += addmark[root];
		sum[root << 1] += addmark[root] * (m - (m >> 1));
		sum[root << 1 | 1] += addmark[root] * (m >> 1);
		addmark[root] = 0;
	}

}
void build(int l, int r, int root)
{
	addmark[root] = 0;
	if (r == l)
	{
		scanf("%lld", &sum[root]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, root << 1);
	build(m + 1, r, root << 1 | 1);
	pushup(root);
}
void update(int L, int R, int l, int r, int root,int c)
{
	if (L <= l&&r <= R)
	{
		addmark[root] += c;
		sum[root] += (long long)c*(r - l + 1);
		return;


	}
	pushdown(root, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, l, m, root << 1,c);
	if (R > m) update(L, R, m + 1, r, root << 1 | 1, c);
	pushup(root);


}
long long  query(int L, int R, int l, int r, int root)
{
	if (L <= l&&r <= R)
	{
		return sum[root];
	}
	pushdown(root, r - l + 1);
	int m = (l + r) >> 1;
	long long ans = 0;
	if (L <= m) ans += query(L, R, l, m, root << 1);
	if (m < R) ans += query(L, R, m + 1, r, root << 1 | 1);
	return ans;

}

int main(void)
{
	int n,q;
	cin >> n >> q;
	build(1, n, 1);
	while (q--)
	{
		char s[5];
		int a, b, c;
		scanf("%s", s);
		if (s[0] == 'Q')
		{
			scanf("%d%d", &a, &b);
			cout << query(a, b, 1, n, 1) << endl;
		}
		else
		{
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, 1, n, 1, c);

		}
	}

	return 0;
}
