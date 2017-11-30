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

const int Maxlen=1000009;
const int Maxsize=26;
const int N=1000009;

struct acauto{
    int next[Maxlen][Maxsize],fail[Maxlen],cnt[Maxlen];
    int root,num;
    int newnode(){
        rep0(i,Maxsize) next[num][i]=-1;
        cnt[num++]=0; return num-1; 
    }
    void init(){ num=0; root=newnode(); }
    void insert(char* st){
        int p=0,u=root;
        while(st[p]) {
            if(next[u][st[p]]==-1) next[u][st[p]]=newnode();
            u=next[u][st[p]]; p++;
        } cnt[u]++;
    }
    void build(){
        queue<int> q; fail[root]=root;
        rep0(i,Maxsize) 
            if(next[root][i]==-1) next[root][i]=root;
            else fail[next[root][i]]=root,q.push(next[root][i]);
        while(!q.empty()) {
            int u= q.front(); q.pop();
            rep0(i,Maxsize) 
                if(next[u][i]==-1) next[u][i]=next[fail[u]][i];
                else fail[next[u][i]]=next[fail[u]][i],q.push(next[u][i]);    
        }    
    }
    ll query(char* st ) { 
    	
        int tmp,p=0,u=root; ll res=0;
        while(st[p])  {
            u=next[u][st[p]]; tmp=u;
            while(tmp!=root) {
                res+=cnt[tmp];  cnt[tmp]=0;
                tmp=fail[tmp];
            } p++;
        }return res;
    }
}ac;

int n;
char s[N];
int main()
{
    int rep; cin>>rep;
    while(rep--){
        scanf("%d",&n);  ac.init();
        rep0(i,n) scanf("%s",s),ac.insert(s);
        ac.build(); scanf("%s",s);
        OUT(ac.query(s));
    }
}