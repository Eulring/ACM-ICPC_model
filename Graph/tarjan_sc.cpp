#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 100009
using namespace std;

int low[N],dfn[N],instack[N],stak[N],head[N];
int snum,step,n,t,m;
struct edge{ int to,next;}e[N];
void addedge(int from,int to){
	e[++t].to=to;
	e[t].next=head[from];
	head[from]=t;
}
void tarjan(int u){
	low[u]=dfn[u]=++step;
	stak[++snum]=u;
	instack[u]=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(instack[v]) low[u]=min(low[u],dfn[v]);
	}int i;
	if(dfn[u]==low[u]){
		do{ i=stak[snum--];
			cout<<i<<" ";
			instack[i]=0;
		}while(i!=u);cout<<endl;
	}
}
void solve(){
	step=snum=0;
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	for(int i=0;i<n;i++)
		if(!dfn[i]) tarjan(i);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int x,y; t=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;i++)
			cin>>x>>y,addedge(x,y);
		solve();
	}
}