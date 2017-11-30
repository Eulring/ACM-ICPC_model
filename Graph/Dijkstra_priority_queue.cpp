#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
const int MAXN=1000010;
using namespace std;
int head[MAXN];
int dist[MAXN],ne;
bool vis[MAXN];
const int INF=0x3f3f3f3f;
struct edge{
    int to,next,w;
}e[MAXN];
void addedge(int from,int to,int w){
    e[++ne].to=to; e[ne].w=w; 
    e[ne].next=head[from];
    head[from]=ne;
}

struct qnode
{
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
void Dijkstra(int num,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=num;i++) 
        dist[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            int cost=e[i].w;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}