#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
#define ff(i,n) for(int i=1;i<=(n);i++)
#define f0(i,n) for(int i=0;i<(n);i++)
#define max(a,b) (a)>(b) ? (a):(b);
#define min(a,b) (a)<(b) ? (a):(b);
#define pb push_back
#define N 11
int mod=1e9+7;
using namespace std;
struct matrix{
	ll mat[N][N]; int n,m;
	matrix(){n=m=N;memset(mat,0,sizeof(mat));}
	ll *operator [](int k){return mat[k];}
};
matrix operator *(matrix &a,matrix &b){
	int i,j,k;
	matrix c;
	c.n=a.n;c.m=b.m;
	ff(i,a.n) ff(j,b.m) ff(k,b.n)
		c[i][j]+=a[i][k]*b[k][j],c[i][j]%=mod;
	return c;	
}
matrix operator ^(matrix &a,int m){
	matrix b,c=a;b.n=a.n;b.m=a.m;
	ff(i,b.n) b[i][i]=1;
	while(m){
		if(m&1) b=b*c;
		if(m>>=1) c=c*c;
	}return b;
}
void ss(matrix &a,int n,int m){a.n=n,a.m=m;}
void pt(ll  a){
	a=a%mod;
	if(a<0) a+=mod;
	cout<<a<<endl;
}
int x,y,n;
int main()
{
	matrix a; ss(a,1,2);//cout<<a.m<<endl;
	matrix e; ss(e,2,2);
	cin>>x>>y>>n;
	a[1][1]=y;a[1][2]=x;
	e[1][1]=1;e[1][2]=1;e[2][1]=-1;
	
	
	if(n==1) pt(x);
	else if(n==2) pt(y);
	else {e=e^(n-2);a=a*e;pt(a[1][1]); }
}