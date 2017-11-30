#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;

const int N = 10101;
int n, m;

struct Edge{
    int u, v, nxt;
    Edge(){}
    Edge(int _u,int _v){
        u = _u; v = _v; nxt = 0;
    }
    int cmp( Edge &t ){
        return (u==t.u&&v==t.v)||(u==t.v&&v==t.u);
    }
    void print(){
        printf("%d->%d ", u, v );
    }
}edge[N<<4];
int head[N], idx;
int dfn[N], low[N], dep;
bool vis[N];
bool gao[N][N];

stack< Edge > S;

void AddEdge(int u,int v)
{
    edge[idx].u = u; edge[idx].v = v;
    edge[idx].nxt = head[u];
    head[u] = idx++;
}
void input(){
    memset(head,-1,sizeof(head));
    idx = 0;
    for(int i = 0; i < m; i++)
    {
        int u , v;
        scanf("%d%d", &u,&v);
        AddEdge(u,v); AddEdge(v,u);
    }
}
void tarjan(int u,int pre)
{
    dfn[u] = low[u] = ++dep;
    vis[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt )
    {
        int v = edge[i].v;
        if( v == pre || gao[v][u] || gao[u][v] ) continue;

        gao[v][u] = gao[u][v] = true;    // 这里要注意标记边.回边也只能走一次.
        S.push( Edge(u,v) );
        if( !vis[v] ){
            tarjan(v,u);
            low[u] = min( low[u], low[v] );
        }
        else low[u] = min( low[u], dfn[v] ); // 回边
        if( low[v] >= dfn[u] ){ //删除顶点U,子节点V所在的子树将脱离.
                Edge t = Edge(u,v);
                while(1)
                {
                    Edge t1 = S.top(); S.pop();
                    t1.print();
                    if( t1.cmp( t ) ) break;
                }
                puts("");
        }
    }
}
void solve(){
    memset( vis, 0, sizeof(vis));
    memset( gao, 0, sizeof(gao));
    dep = 0;
    tarjan(1,0);
}
int main()
{
    //freopen("1.txt","r",stdin);
    //while( scanf("%d%d", &n,&m) != EOF)
    scanf("%d%d", &n,&m);
    {
        input();
        solve();
    }
    cin>>n;
    return 0;
}
