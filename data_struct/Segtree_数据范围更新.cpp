#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define lson rt*2
#define rson rt*2|1
#define N 260000
typedef long long ll;
int n,m,q;
ll a[N];
struct node{
	int left,right;
	ll Max,Min,add;
	int mid(){return left+(right-left)/2;}
	void fun(ll x) {
		Max+=x; Min+=x; add+=x;
	}
};
struct segtree{
	node t[N*4];
	void pushup(int rt){
		t[rt].Max=max(t[lson].Max,t[rson].Max);
		t[rt].Min=min(t[lson].Min,t[rson].Min);
	}
	void relax(int rt) {
		if(t[rt].add!=0) {
			t[lson].fun(t[rt].add);
			t[rson].fun(t[rt].add);
			t[rt].add=0;
		}
	}
	void build(int l,int r,int rt) {
		t[rt].left=l; t[rt].right=r;
		if(l==r) {
			t[rt].Max=a[l]; t[rt].Min=a[l];
			t[rt].add=0;
			return ;
		}	
		int mid=t[rt].mid();
		build(l,mid,lson); build(mid+1,r,rson);
		pushup(rt);
	}
	void update(int l,int r,int rt,int add) {
		
		if(t[rt].Min>=l&&t[rt].Max<=r) {
			t[rt].fun(add); return ;
		}
		relax(rt);
		if(!(r<t[lson].Min||l>t[lson].Max))
			update(l,r,lson,add); 
		if(!(r<t[rson].Min||l>t[rson].Max))
			update(l,r,rson,add);
		pushup(rt);
	}
	int query(int l,int r,int rt) {
		//cout<<t[rt].left<<" "<<t[rt].right<<endl;		
		if(t[rt].Min>=l&&t[rt].Max<=r) 
			return t[rt].right-t[rt].left+1;
		relax(rt);
		int sum1=0,sum2=0;
		//cout<<" "<<t[lson].Max<<" "<<t[lson].Min<<endl;
		//cout<<" "<<t[rson].Max<<" "<<t[rson].Min<<endl;
		//printf("%d %d %d \n",l,t[lson].Max,t[lson].Min);
		if(!(r<t[lson].Min||l>t[lson].Max))
			sum1=query(l,r,lson); 
		if(!(r<t[rson].Min||l>t[rson].Max))
			sum2=query(l,r,rson);	
		return sum1+sum2;
	}
	void push_all(int rt) {
		if(t[rt].left==t[rt].right) {
			a[t[rt].left]=t[rt].Max; return ;
		}
		relax(rt);
		push_all(lson); push_all(rson);	
	}

}seg;


char s[12];
//数据范围更新 
int main()
{
	int x,y,z;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
		sort(a+1,a+1+n);
		seg.build(1,n,1);
		for(int i=1;i<=q;i++) {
			scanf("%s",s);
			if(s[0]=='Q') {
				scanf("%d%d",&x,&y);
				printf("%d\n",seg.query(x,y,1));
			}
			else {
				scanf("%d%d%d",&x,&y,&z);
				seg.update(x,y,1,z);
			}
			
			if(i%4000==0) {
				seg.push_all(1);
				sort(a+1,a+1+n);
				seg.build(1,n,1);
			}
			
		}	
	}
}