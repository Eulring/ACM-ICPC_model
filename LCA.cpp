#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
#define INF 2147483647
#define PI 3.1415926
#define N 100009
typedef long long ll;

int fa[20][N],n;
int father[N],deep[N];
void build() {
	for (int i = 1; i <= n; ++i) 
		fa[0][i] = father[i];
	for (int k = 1; k < 20; ++k) 
		for (int i = 1; i <= n; ++i)
			fa[k][i] = fa[k-1][fa[k-1][i]];
}
int query(int x, int y) {
	if (deep[x] > deep[y]) std::swap(x, y);
	int h = deep[y] - deep[x];
	for (int k = 19; k >= 0; --k) {
		if (h >= (1 << k)) {
			h -= 1 << k;
			y = fa[k][y];
		}
	}
	if (x == y) return x;
	for (int k = 19; k >= 0; --k) {
		if (fa[k][x] == fa[k][y]) continue;
		x = fa[k][x], y = fa[k][y];
	}
	return fa[0][x];
}
void bfs(int s) {
	queue<int> q;
	q.push(s); 
	deep[s] = 1;
	father[s] = s;
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; ~i; i = e[i].next) {
			int v = e[i].to;
			if (deep[v]) continue;
			q.push(v);
			deep[v] = deep[u] + 1;
			father[v] = u;
			dis[v] = dis[u] + e[i].w;
		}
	}
}

