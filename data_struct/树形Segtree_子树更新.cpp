#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100111
std::vector<int> e[N];
int ind[N],a[N],num,pos[N];
struct node {
	int left,right,tmp,v;
	void fun(int x) { tmp=x; v=x; }
};
struct segtree {
	node tree[N*2];
	void relax(int rt) {
		if(tree[rt].tmp>-1){
			tree[rt].v=tree[rt].tmp; 
			for(int i=tree[rt].left;i<tree[rt].right;i++)
				tree[a[i]].fun(tree[rt].v);
			tree[rt].tmp=-1;	
		}
	}
	void build(int rt) {
		tree[rt].left=num+1;
		for(int i=0;i<e[rt].size();i++) {
			build(e[rt][i]);
		}
		tree[rt].tmp=-1; tree[rt].v=-1;
		tree[rt].right=++num; a[num]=rt; pos[rt]=num;
	}
	void update(int x,int rt,int v) {
		//cout<<x<<" "<<rt<<endl; 
		if(x==rt) {
			tree[rt].fun(v); return ;
		}		
		for(int i=0;i<e[rt].size();i++){
			int t=e[rt][i]; //cout<<t<<endl;
			if(pos[x]<=tree[t].right&&pos[x]>=tree[t].left) 
				{relax(rt);update(x,t,v);}
		}
	}
	int query (int x,int rt){ 
		//cout<<x<<" "<<rt<<endl;
		if(x==rt) return tree[rt].v;
		for(int i=0;i<e[rt].size();i++){
			int t=e[rt][i]; //cout<<t<<endl;
			if(pos[x]<=tree[t].right&&pos[x]>=tree[t].left) 
				{relax(rt); return query(x,t);}
		}
	}
	void pt() {
		for(int i=1;i<=num;i++)
			printf("%d %d\n",tree[i].left,tree[i].right);
	}
}seg;
int main()
{
	int q,n,rep,cas=0,x,y,root;cin>>rep;
	char c[12];
	while(rep--) {
		scanf("%d",&n);  num=0;
		memset(ind,0,sizeof(ind));
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			e[y].push_back(x); ind[x]++;
		}	
		for(int i=1;i<=n;i++)
			if(ind[i]==0) root=i,seg.build(i);
		scanf("%d",&q);printf("Case #%d:\n",++cas);  
		while(q--) {
			
			scanf("%s",c);
			if(c[0]=='C') {
				scanf("%d",&x);
				printf("%d\n",seg.query(x,root));
			}	
			else {
				scanf("%d%d",&x,&y);
				seg.update(x,root,y);
			}
		}
		
	}
}