//ÈôÎª¸î±ß(u,v) ,  dfn[u]<low[v] 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#define N 12000
#define m_p make_pair
typedef long long ll;
using namespace std;
int head[N],dfn[N],low[N];
int n,m,vis[N],t,dep;
map<pair<int,int>,int> mp;
vector<int> ans;
struct edge{
	int to,next,tag;
}e[N*100];
void addedge(int from,int to){
	for(int i=head[from];i!=-1;i=e[i].next){
		if(e[i].to==to) {
			e[i].tag=1; return ;	
		}
	}
	e[++t].to=to;
	e[t].next=head[from];
	e[t].tag=0;
	head[from]=t;
}
void init(){
	memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(head,-1,sizeof(head));
	t=0; dep=0;
	mp.clear(); ans.clear();
}
void dfs(int pre,int u){
	dfn[u]=low[u]=++dep;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].to;
		if(v==pre) continue;
		if(vis[v]) low[u]=min(low[u],dfn[v]);
		else {
			dfs(u,v);
			low[u]=min(low[v],low[u]);
		}
		if(low[v]>dfn[u]&&!e[i].tag){
			int x=mp[m_p(u,v)];
			ans.push_back(x);
		}
	}
}
int main()
{
	int rep,cas=0,x,y; cin>>rep;
	for(int cas=0;cas<rep;cas++){
		scanf("%d%d",&n,&m);
		init();
		if(cas) puts("");
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
			mp[m_p(x,y)]=mp[m_p(y,x)]=i;
		}
		dfs(0,1); 
		sort(ans.begin(),ans.end());
		x=ans.size();
		printf("%d\n",ans.size());
		for(int i=0;i<x;i++){
			if(i) cout<<" ";
			printf("%d",ans[i]);
			if(i==x-1) cout<<endl;
		}
	}
}
