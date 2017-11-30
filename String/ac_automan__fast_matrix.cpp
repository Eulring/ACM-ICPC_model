#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <queue>
using namespace std;
#define clr(arr, val)    memset(arr, val, sizeof(arr))
#define rep0(i, n)       for(int (i) = 0; (i) < (n); ++(i))
#define rep(i, l, h)    for(int (i) = (l); (i) <= (h); ++(i))
#define rrep(i, h, l)   for(int (i) = (h); (i) >= (l); --(i))
#define lson    (x) << 1
#define rson    (x) << 1 | 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define Read()  freopen("data.in", "r", stdin)
#define Write() freopen("data.out", "w", stdout);
typedef long long ll;

const int Maxlen=1009;
const int Maxsize=4;
const int N=109;
ll mod=1e5;

//n长度的字符串不存在多个特定模式串的数量 
struct matrix{
    ll mat[N][N]; int n,m;
    matrix(){n=m=N;memset(mat,0,sizeof(mat));}
    void init(){memset(mat,0,sizeof(mat));}
    ll *operator [](int k){return mat[k];}
}mt;
matrix operator *(matrix &a,matrix &b){
    int i,j,k;
    matrix c;
    c.n=a.n;c.m=b.m;
    rep(i,1,a.n) rep(j,1,b.m) rep(k,1,b.n)
        c[i][j]+=a[i][k]*b[k][j],c[i][j]%=mod;
    return c;   
}
matrix operator ^(matrix &a,int m){
    matrix b,c=a;b.n=a.n;b.m=a.m;
    rep(i,1,b.n) b[i][i]=1;
    while(m){
        if(m&1) b=b*c;
        if(m>>=1) c=c*c;
    }return b;
}
void ss(matrix &a,int n,int m){a.n=n,a.m=m;}


struct acauto{
    int next[Maxlen][Maxsize],fail[Maxlen],cnt[Maxlen];
    int id[500],tag[Maxlen];
    int root,num;
    int newnode(){
        rep0(i,Maxsize) next[num][i]=-1;
        cnt[num++]=0; return num-1; 
    }
    void init(){ 
        num=0; root=newnode(); clr(tag,0); 
        id['A']=1,id['T']=2,id['G']=3,id['C']=0;
    }
    void insert(char* st){
        int p=0,u=root,tx; 
        while(st[p]) {  tx=id[st[p]]; 
            if(next[u][tx]==-1) next[u][tx]=newnode();
            u=next[u][tx]; p++;
        } cnt[u]++; tag[u]=1;
    }
    void build(){
        queue<int> q; fail[root]=root;
        rep0(i,Maxsize) 
            if(next[root][i]==-1) next[root][i]=root;
            else fail[next[root][i]]=root,q.push(next[root][i]);
        while(!q.empty()) {
            int u=q.front(); q.pop();
            if(tag[fail[u]]) tag[u]=1;
            rep0(i,Maxsize) 
                if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
                else fail[next[u][i]]=next[fail[u]][i],q.push(next[u][i]);    
        }    
    }
    void buildmat(){
        mt.init(); ss(mt,num,num);
        rep0(i,num) rep0(j,Maxsize) 
            if(!(tag[i]||tag[next[i][j]])) 
                mt[i+1][next[i][j]+1]++;
                
    }

}ac;



int qp(int n){
    mt=mt^n;
    int ans=0;
    rep(i,1,mt.n) ans+=mt[1][i];
    return ans%mod;
}




char s[N];
int main()
{   
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        ac.init();
        rep0(i,m) scanf("%s",s),ac.insert(s);
        ac.build(); ac.buildmat(); 
        printf("%d\n",qp(n));
    }
}