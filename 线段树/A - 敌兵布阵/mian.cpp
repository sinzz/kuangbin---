#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 50505;//�ڵ����
int tree[maxn << 2 ];
void pushup(int rt)
{
	tree[rt] = tree[rt << 1] + tree[(rt << 1) + 1];

}
void build(int l, int r, int rt)//��������Ϊl r ���ڵ�Ϊrt ���߶���
{
	if (l == r) //���䳤��Ϊ 0 �� ¼��rt �ڵ��ֵ
	{
		scanf("%d", &tree[rt]);
		return;
	}
	int m = (l + r) >> 1;// ��ȡ�����е�
	build(l, m, rt << 1);//����������
	build(m + 1, r, (rt << 1)+1);//����������
	pushup(rt);//���������ֵ
}
void updata(int pos, int addn, int l, int r, int rt)//����posλ�õ����� ������Ϊaddn
{
	if (l == r) //���䳤��Ϊ 0 �ҵ��ýڵ� ��ʼ��������
	{
		tree[rt] += addn;
		return;
	}
	int m = (l + r) >> 1;
	if (pos <= m)//�ж�pos ���ڵ����� ��������
		updata(pos, addn, l, m, rt << 1);
	else
		updata(pos, addn, m + 1, r, (rt << 1) + 1);
	pushup(rt);
	
}
int query(int L, int R, int l, int r, int rt)//������l��r ��������L��R����ֵ
{
	if (L <= l&&R >= r)//ȷ��l r ���������L R���� ��ֱ�ӷ���ֵ
	{
		return tree[rt];
	}
	int m = (r + l) >> 1;
	int ret = 0;
	if (L <= m) //��ʼͳ��
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