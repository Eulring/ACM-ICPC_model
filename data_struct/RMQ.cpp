#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define N 110089
#define M 400009
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define Min(a,b) (a)<(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define Clr(a) memset(a,0,sizeof(a))
#define MID(a,b) (a+((b-a)>>1)) 
#define Lbit(a) (x)&(-(x))
const int INF=1LL<<60-1;  
const int lim=1<<25+1; 
int n,m,k;
int Max(int a,int b){return a>b?a:b;}
int rq[N][22];
void init(){
	ff(i,20) ff(j,n)
		if(j+(1<<i)-1<=n)
			rq[j][i]=Max(rq[j][i-1],rq[j+(1<<(i-1))][i-1]);
}
int rmq(int l,int r){
	int d=log2(r-l+1);
	return Max(rq[l][d],rq[r-(1<<d)+1][d]);
}
int main()
{
	cin>>n;
	ff(i,n) scanf("%d",&rq[i][0]);
	init();
	int l,r;
	while(scanf("%d%d",&l,&r)!=EOF)
		cout<<rmq(l,r)<<endl;	
}