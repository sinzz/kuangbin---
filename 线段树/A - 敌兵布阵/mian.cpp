#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 50505;//节点个数
int tree[maxn << 2 ];
void pushup(int rt)
{
	tree[rt] = tree[rt << 1] + tree[(rt << 1) + 1];

}
void build(int l, int r, int rt)//建立区间为l r 根节点为rt 的线段树
{
	if (l == r) //区间长度为 0 是 录入rt 节点的值
	{
		scanf("%d", &tree[rt]);
		return;
	}
	int m = (l + r) >> 1;// 求取区间中点
	build(l, m, rt << 1);//建左左子树
	build(m + 1, r, (rt << 1)+1);//建立右子树
	pushup(rt);//更新区间的值
}
void updata(int pos, int addn, int l, int r, int rt)//更新pos位置的数据 增加量为addn
{
	if (l == r) //区间长度为 0 找到该节点 开始更新数据
	{
		tree[rt] += addn;
		return;
	}
	int m = (l + r) >> 1;
	if (pos <= m)//判断pos 所在的区间 更新数据
		updata(pos, addn, l, m, rt << 1);
	else
		updata(pos, addn, m + 1, r, (rt << 1) + 1);
	pushup(rt);
	
}
int query(int L, int R, int l, int r, int rt)//从区间l到r 查找区间L到R的数值
{
	if (L <= l&&R >= r)//确定l r 区间包含于L R区间 则直接返回值
	{
		return tree[rt];
	}
	int m = (r + l) >> 1;
	int ret = 0;
	if (L <= m) //开始统计
		ret += query(L, R, l, m, rt << 1);
	if (R > m)
		ret += query(L, R, m + 1, r, (rt << 1) + 1);
	return ret;

}


int main(void)
{
	int t, n;
	int cnt = 0;
	cin >> t;
	while (t--)
	{
		cout << "Case " << ++cnt << ":" << endl;
		cin >> n;
		build(1, n, 1);
		char s[10];
		while (scanf("%s",s))
		{
			if (s[0] == 'E')
				break;
			int  x, y;
			scanf("%d%d", &x, &y);
			if (s[0] == 'Q')
				cout << query(x, y, 1, n, 1) << endl;
			if (s[0] == 'A')
				updata(x, y, 1, n, 1);
			if (s[0] == 'S')
				updata(x, -y, 1, n, 1);

		}
	
	}



	return 0;
}