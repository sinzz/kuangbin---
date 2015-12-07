#include <stdio.h>
#include <stdlib.h>
#define  N 1010
int rep[N];
int num, d;
struct node
{
	int pre;
	int x;
	int y;
}pre[N];
int find(int x)
{
	int r = x;
	while (pre[r].pre != r)
		r = pre[r].pre;
	return r;
}
void join(struct node a, struct node b)
{
	int roota = find(a.pre);
	int rootb = find(b.pre);
	if (roota != rootb)
	if ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) <= d*d)
		pre[roota].pre = rootb;

}

int main(void)
{
	scanf("%d%d", &num, &d);
	for (int i = 0; i < num; i++){
		pre[i].pre = i;
		scanf("%d%d", &pre[i].x, &pre[i].y);
	}
	char op;
	int o1, s1, s2;
	while (scanf("\n%c", &op) != EOF)
	{
		if (op == 'O')
		{
			scanf("%d", &o1);
			rep[o1 - 1] = 1;
			for (int i = 0; i < num; i++)
			{
				if (rep[i] && i != o1 - 1)
					join(pre[i], pre[o1 - 1]);
			}

		}
		else
		{
			scanf("%d%d", &s1, &s2);
			if (find(s1 - 1) == find(s2 - 1))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}