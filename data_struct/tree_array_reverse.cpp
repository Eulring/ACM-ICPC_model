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
#define Max(a,b) (a)>(b)?(a):(b)
#define Abs(a) (a)<0?-(a):(a)
#define Clr(a) memset(a,0,sizeof(a))
#define MID(a,b) (a+((b-a)>>1)) 
#define Lbit(a) (x)&(-(x))
int n,s[N];
int lb(int x){return x&(-x);}
int sum(int x){
	int ans=0;
	while(x)
		ans+=s[x],x-=lb(x);
	return ans;
}
void update(int x){
	while(x<=(n+1))
		s[x]++,x+=lb(x);
}
int a[N],b[N];
int main()
{
	cin>>n;
	ff(i,n) cin>>a[i];
	Clr(s);
	for(int j=n;j;j--)
		b[j]=sum(a[j]),update(a[j]);
	ff(i,n) cout<<b[i]<<" "; cout<<endl;	
	Clr(s);
	for(int i=1;i<=n;i++){
		int l=0,r=n;
		while(r-l>1){
			int m=(l+r)>>1;
			if(m-sum(m+1)>b[i]) r=m;
			else l=m;
		}cout<<r<<" ";
		update(r+1);
	}cout<<endl;
}