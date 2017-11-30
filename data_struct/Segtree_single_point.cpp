#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
#define N 110000
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define min(a,b) (a)<(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define clr(a) memset(a,0,sizeof(a))  
struct node{
	int left,right,sum;
	int mid(){return left+(right-left)/2;}
};
struct segtree{
	node tree[N*4];
	void build(int l,int r,int p){
		tree[p].left=l;
		tree[p].right=r;
		tree[p].sum=0;
		if(l==r){
			scanf("%d",&tree[p].sum);
			return ;
		}
		else{
			int mid=tree[p].mid();
			build(l,mid,p*2);
			build(mid+1,r,p*2+1);
		}
		tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
	}
	void update(int pos,int v,int p){
		tree[p].sum+=v;
		int l=tree[p].left;
		int r=tree[p].right;
		int mid=tree[p].mid();
		if(l==pos&&r==l) return ;
		else if(mid>=pos) update(pos,v,p*2);
		else if(mid<pos) update(pos,v,p*2+1);
	}
	int query(int st,int ed,int p){
		int l=tree[p].left;
		int r=tree[p].right;
		int mid=tree[p].mid();
		if(st<=l&&ed>=r) return tree[p].sum;
		int sum=0;
		if(st<=mid) sum+=query(st,ed,p*2);
		if(ed>mid) sum+=query(st,ed,p*2+1);
		return sum;
	}
}seg;
int main()
{
    int rep,cas=0;cin>>rep;
    int x,y,p,val,n;
    char s[30];
    while(rep--){
        scanf("%d",&n);
        seg.build(1,n,1);
       
        printf("Case %d:\n",++cas);
        while(1){
            scanf("%s",s);
            if(s[0]=='E') break;
            scanf("%d%d",&x,&y);
            if(s[0]=='Q')
            	printf("%d\n",seg.query(x,y,1));
            else if(s[0]=='S') 
            	seg.update(x,-y,1);
            else if(s[0]=='A') 
            	seg.update(x,y,1);
        }
    }
    //seg.build(1,n,1);
    //seg.query(start,end,1);
    //seg.update(position,1,addsval);
}
