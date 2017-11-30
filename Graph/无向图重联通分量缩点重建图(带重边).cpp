
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define M 1000100
#define N 200010
#define pb push_back
int n,m;
int dfn[N],head[N],low[N],vis[N],belong[N];
int st[N],stn,dep,t,cnt;
int eg[M][2],ne;
int ep,maxlen;
struct edge{
    int next,to,flag;
}e[M*2];
void addedge(int from,int to){
    e[t].to=to; e[t].next=head[from];
    e[t].flag=0;  head[from]=t++;
    e[t].to=from; e[t].next=head[to];
    e[t].flag=0;  head[to]=t++;
}
void init(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    dep=0; t=0; stn=0; ne=0; cnt=0; 
}
void tarjan(int u){
    vis[u]=1;
    dfn[u]=low[u]=++dep;
    st[++stn]=u;    
    for(int i=head[u];i+1;i=e[i].next){
        if(e[i].flag) continue;  
        e[i].flag=1; e[i^1].flag=1;
        int to=e[i].to;
        if(vis[to])
            low[u]=min(low[u],dfn[to]);
        else{
            tarjan(to);
            low[u]=min(low[u],low[to]);
            if(dfn[u]<low[to]){
                eg[ne][0]=u;
                eg[ne++][1]=to;
            }
        }
    }
    if(dfn[u]==low[u]){
        int tmp;
        do{
            belong[st[stn]]=cnt;
            tmp=st[stn--];
        }while(tmp!=u);
        cnt++; 
    } 
}
int main()
{    
    int x,y;
    while(scanf("%d%d",&n,&m)&&(n+m)){
        init();

        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }

        tarjan(1);

        t=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<ne;i++){
            addedge(belong[eg[i][0]],belong[eg[i][1]]);
        }
    }
}