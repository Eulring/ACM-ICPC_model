#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define lb(x) (x)&(-x)
#define N 300
int INF=1<<30;
struct edge {int to,next,f;}e[N*N*2];
int ne,head[N];
void init() {
	ne=0; memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int f) {
	e[ne].to=v; e[ne].f=f; e[ne].next=head[u];
	head[u]=ne++;
	e[ne].to=u; e[ne].f=0; e[ne].next=head[v];
	head[v]=ne++;
}

int lev[N];
int bfs(int st,int ed) {
	queue<int> q;   q.push(st);
	memset(lev,0,sizeof(lev)); lev[st]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int i=head[u];i+1;i=e[i].next) {
			int v=e[i].to;
			if(lev[v]==0&&e[i].f) 
				lev[v]=lev[u]+1,q.push(v);
		}
	}
	return lev[ed]!=0;
}
int dfs(int u,int ed,int flow) {
	int t=0;
	if(u==ed) return flow;
	for(int i=head[u];i+1;i=e[i].next) {
		int v=e[i].to;
		if(lev[u]!=lev[v]-1) continue;
		if(!e[i].f) continue;
		if(t=dfs(v,ed,min(flow,e[i].f))){
			e[i].f-=t; e[i^1].f+=t;
			return t;
		}
	}
	return 0;
}
void dinic(int st,int ed) {
	int ans=0;
	while(bfs(st,ed)) 
		ans+=dfs(st,ed,INF);
	printf("%d\n",ans);
}
int main()
{
	int n,m,x,y,z;
	while(scanf("%d%d",&m,&n)!=EOF) {
		init();
		for(int i=1;i<=m;i++) {
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);		
		}
		dinic(1,n);
	}
}