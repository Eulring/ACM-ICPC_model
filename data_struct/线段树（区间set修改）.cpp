#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAX=1000;
int sum[MAX*2],Min[MAX*2],Max[MAX*2];
int set[MAX*2];
void Init()
{
	memset(sum,0,sizeof(sum));
	memset(Min,3,sizeof(Min));
	memset(Max,0,sizeof(Max));
	memset(set,-1,sizeof(set));
}

void maintain(int o,int L,int R)
{
	sum[o]=Min[o]=Max[o]=0;
	if(L<R)
	{
		sum[o]=sum[o*2]+sum[o*2+1];
		Min[o]=min(Min[o*2],Min[o*2+1]);
		Max[o]=max(Max[o*2],Max[o*2+1]);
	}
	/********************************/
	if(set[o]>=0)
	{
		sum[o]=set[o]*(R-L+1);
		Min[o]=set[o];
		Max[o]=set[o];
	}
	/*******************************/
}
void pushdown(int o)//标记 
{
	if(set[o]>=0)
	{
		set[o*2]=set[o*2+1]=set[o];
		set[o]=-1;
	}
}
//更新 
void updata(int o,int L,int R,int ul,int ur,int v)
{
	int mid=(L+R)/2;
	if(ul<=L&&R<=ur)
	{
		set[o]=v;
	}
	else
	{
		pushdown(o);//标记 
		if(ul<=mid) 
			updata(o*2,L,mid,ul,ur,v);
		else
			maintain(o*2,L,mid);
		if(mid<ur) 
			updata(o*2+1,mid+1,R,ul,ur,v);
		else
			maintain(o*2+1,mid+1,R);
	}
	maintain(o,L,R);
}
//查询 
int __sum,__min,__max;
void query(int o,int L,int R,int ql,int qr)
{
	int mid=(L+R)/2;
	if(set[o]>=0)//递归边界1：有set标记 
	{
		__sum+=set[o]*(min(R,qr)-max(L,ql)+1);
		__min=min(__min,set[o]);
		__max=max(__max,set[o]);
	}
	else if(ql<=L&&R<=qr)//递归边界2：不受set标记的影响 
	{
		__sum+=sum[o];
		__min=min(__min,Min[o]);
		__max=max(__max,Max[o]);
	} 
	else
	{
		if(ql<=mid)
			query(o*2,L,mid,ql,qr);
		if(mid<qr)
			query(o*2+1,mid+1,R,ql,qr);
	}
}
int main()
{
	Init();
	for(int i=0;i<100;i++)
	{
		int v,l,r;
		scanf("%d%d%d",&l,&r,&v);
		updata(1,1,20,l,r,v);
		scanf("%d%d",&l,&r);
		__sum=0;
		__min=0x3ffffff;
		__max=-9999999;
		query(1,1,20,l,r);
		printf("sum=%d\nmin=%d\nmax=%d\n",__sum,__min,__max);
	}
	return 0;
}

/*
1 11 1
1 5
3 8 2
1 5
4 9 3
1 5
*/ 