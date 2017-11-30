#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 100100;
const int INF = 0x3f3f3f3f;
int Abs(int x){if(x<0) x=-x; return x;}
struct Edge
{
    int to,next,cap,flow,cost;
}e[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;
void addedge(int u,int v,int cap,int cost)
{
    e[tol].to = v;
    e[tol].cap = cap;
    e[tol].cost = cost;
    e[tol].flow = 0;
    e[tol].next = head[u];
    head[u] = tol++;
    e[tol].to = u;
    e[tol].cap = 0;
    e[tol].cost = -cost;
    e[tol].flow = 0;
    e[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0;i < N;i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u];i != -1;i = e[i].next)
        {
            int v = e[i].to;
            if(e[i].cap > e[i].flow && 
                    dis[v] > dis[u] +e[i].cost)
            {
                dis[v] = dis[u] + e[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t];i != -1 ;i = pre[e[i^1].to])
        {
            if(Min > e[i].cap - e[i].flow)
                Min = e[i].cap - e[i].flow;
        }
        for(int i = pre[t];i != -1;i = pre[e[i^1].to])
        {
            e[i].flow += Min;
            e[i^1].flow -= Min;
            cost += e[i].cost*Min;
        }
        flow += Min;
    }
    return flow;
}
