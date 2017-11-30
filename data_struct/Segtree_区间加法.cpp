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
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define Clr(a) memset(a,0,sizeof(a))
#define MID(a,b) (a+((b-a)>>1))  
int a[N];
struct node{
	int left,right;
	ll val,add;
	int mid(){return left+(right-left)/2;}
	void fun(ll x){
		add+=x;
		val+=(right-left+1)*x;
	}
};
struct segtree{
	node tree[N*4];
	void relax(int rt){
		if(tree[rt].add!=0){	
			tree[rt*2].fun(tree[rt].add);
			tree[rt*2+1].fun(tree[rt].add);
			tree[rt].add=0;
		}
	}
	void build(int l,int r,int rt){
		tree[rt].left=l;
		tree[rt].right=r;
		tree[rt].add=0;
		if(l==r){
			tree[rt].val=a[l];
			return ;
		}
		int mid=tree[rt].mid();
		build(l,mid,rt*2);
		build(mid+1,r,rt*2+1);
		tree[rt].val=tree[rt*2].val+tree[rt*2+1].val;
	}
	void change(int st,int ed,int v,int rt){
		int left=tree[rt].left;
		int right=tree[rt].right;
		if(left>=st&&right<=ed){
			tree[rt].fun(v);
			return ;
		}
		relax(rt);
		int mid=tree[rt].mid();
		if(st<=mid) change(st,ed,v,rt*2);
		if(ed>mid) change(st,ed,v,rt*2+1);
		tree[rt].val=tree[rt*2].val+tree[rt*2+1].val;
	}
	ll query(int st,int ed,int rt){
		int left=tree[rt].left;
		int right=tree[rt].right;
		if(left>=st&&right<=ed) 
			return tree[rt].val;
		relax(rt);
		int mid=tree[rt].mid();
		ll res=0;
		if(st<=mid) res+=query(st,ed,rt*2);
		if(ed>mid) res+=query(st,ed,rt*2+1);
		return res; 
	}
}seg;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int x,y,z; char op;
		ff(i,n) scanf("%d",&a[i]);
		seg.build(1,n,1);
		while(m--){
			getchar();scanf("%c",&op); 
			if(op=='Q'){
				scanf("%d%d",&x,&y);
				printf("%lld\n",seg.query(x,y,1));
			}
			else {
				scanf("%d%d%d",&x,&y,&z);
				seg.change(x,y,z,1);
			}
		}	
	}
}