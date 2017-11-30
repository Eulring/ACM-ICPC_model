#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
#define N 110089
#define M 400009
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define Clr(a) memset(a,0,sizeof(a))
#define MID(a,b) (a+((b-a)>>1)) 
#define Lbit(a) (x)&(-(x))
const int INF=1<<30-1;  
const int lim=1<<25+1; 
int cnt=0,pre[N],dep[N],cur[N],gap[N],head[N];
struct edge{int to,next,c,f;}e[M];
void init(){
	cnt=0; memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0){
	e[cnt].to=v; e[cnt].c=w; e[cnt].f=0;
	e[cnt].next=head[u],head[u]=cnt++;
	e[cnt].to=u; e[cnt].c=rw; e[cnt].f=0;
	e[cnt].next=head[v],head[v]=cnt++;
}
int isap(int st,int ed,int num){
	memset(gap,0,sizeof(gap));
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	int u=st;
	pre[u]=-1;
	gap[0]=num;
	int ans=0;
	while(dep[st]<num){ //
		if(u==ed) {//cout<<1;
			int mi=INF;
			for(int i=pre[u];i!=-1;i=pre[e[i^1].to])
				if(mi>e[i].c-e[i].f)
					mi=e[i].c-e[i].f;
			for(int i=pre[u];i!=-1;i=pre[e[i^1].to])
				e[i].f+=mi,e[i^1].f-=mi;
			u=st; ans+=mi; continue;		
		}
		bool flag=false;
		int v;
		for(int i=cur[u];i!=-1;i=e[i].next) {
			v=e[i].to;
			if(e[i].c-e[i].f&&dep[v]+1==dep[u]){
				flag=true;
				cur[u]=pre[v]=i;
				break;
			}
		}
		if(flag) {
			u=v; continue;
		}
		int mi=num;
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i].c-e[i].f&&dep[e[i].to]<mi)
				mi=dep[e[i].to],cur[u]=i;
		gap[dep[u]]--;
		if(!gap[dep[u]]) return ans;
		dep[u]=mi+1;
		gap[dep[u]]++;
		if(u!=st) u=e[pre[u]^1].to;			
	}
	return ans;
}
int main()
{
	init();
	int n,m; cin>>n>>m;
	ff(i,m) {
		int x,y,z; cin>>x>>y>>z;
		addedge(x,y,z);
	}//cout<<cnt<<endl;
	cout<<isap(1,n,n)<<endl;
}