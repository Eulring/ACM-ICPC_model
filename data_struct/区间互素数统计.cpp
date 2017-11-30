#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
#define N 310000
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define Clr(a) memset(a,0,sizeof(a))
int n,m,ans[N],tree[N*4],mx;
int headq[N],headl[N],headr[N];
struct ques{int l,r,next;}q[N];
struct point{int v,l,r,nl,nr;}p[N];
void add_q(int i,int l){
    q[i].next=headq[l];
    headq[l]=i;
}
void add_l(int i,int pos){
    p[i].nl=headl[pos];
    headl[pos]=i;
}

void get_head(){
    ff(i,n) add_l(i,p[i].l);
    ff(i,m) add_q(i,q[i].l);
}

int pos[N];
void  get_l_r(){ 
    ff(i,n) p[i].r=n+1,p[i].l=0;
    ff(i,mx) pos[i]=0;
    
    for(int i=1;i<=n;i++){
    	int x=p[i].v;
    	for(int j=2;j*j<=x;j++){
    		if(x%j==0) {
    			p[i].l=Max(p[i].l,pos[j]);
    			pos[j]=i;
    		}
    		while(x%j==0) x/=j;
    	}
    	if(x>1) {
			p[i].l=Max(p[i].l,pos[x]);
			pos[x]=i;
    	}
    }

    ff(i,mx) pos[i]=n+1;
    for(int i=n;i;i--){
    	int x=p[i].v;
    	for(int j=2;j*j<=x;j++){
    		if(x%j==0){
    			p[i].r=Min(p[i].r,pos[j]);
    			pos[j]=i;
    		}
    		while(x%j==0) x/=j;
    	}
    	if(x>1){
	    	p[i].r=Min(p[i].r,pos[x]);
	    	pos[x]=i;
	    }
    }
    //ff(i,n) cout<<p[i].v<<" "<<p[i].l<<" "<<p[i].r<<endl; 
}


int lb(int x){return x&(-x);}
void add(int x,int adds){
    for(;x<=n;tree[x]+=adds,x+=lb(x));
}
int sum(int x){
    int ans=0;
    for(;x>0;ans+=tree[x],x-=lb(x));
    return ans;    
}

void init(){
    f0(i,n+2) 
        headl[i]=headr[i]=headq[i]=-1;  
    ff(i,4*n) tree[i]=lb(i);
}

int main()
{
    while(scanf("%d%d",&n,&m)&&n+m){
        init(); mx=0;
        ff(i,n) scanf("%d",&p[i].v),mx=Max(mx,p[i].v);
        ff(i,m) scanf("%d%d",&q[i].l,&q[i].r);
        get_l_r();
        get_head();  
        for(int i=1;i<=n;i++){
            for(int j=headl[i-1];j!=-1;j=p[j].nl)
                add(j,-1),add(p[j].r,1);
            for(int j=headq[i];j!=-1;j=q[j].next){
                ans[j]=sum(q[j].r)-sum(q[j].l-1);
                ans[j]=q[j].r+1-q[j].l-ans[j];
            }
            add(p[i].r,-1);
        }
        ff(i,m) cout<<ans[i]<<endl;
    }
} 
