#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;
int fa[maxn], sum[maxn];
int n, m, l, r, s;
int findFa(int x){
	if (x != fa[x]){
		int t = fa[x];
		fa[x] = findFa(fa[x]);
		sum[x] += sum[t];
	}
	return fa[x];
}
int main(){
	while (~scanf("%d%d", &n, &m)){
		for (int i = 0; i <= n; ++i){
			fa[i] = i;
			sum[i] = 0;
		}
		int ans = 0;
		while (m--){
			scanf("%d%d%d", &l, &r, &s);
			l--;
			int pa = findFa(l), pb = findFa(r);
			if (pa == pb){
				if (sum[r] - sum[l] != s) ans++;
			}
			else {
				fa[pb] = pa;
				sum[pb] = sum[l] - sum[r] + s;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}