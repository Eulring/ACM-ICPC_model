#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 211111
typedef long long ll;
ll mod=1000000007;
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=x;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else {x=1;y=0;}
	return d;
}
ll mod_inverse(ll a){
	ll x,y;
	extgcd(a,mod,x,y);
	return (mod+x%mod)%mod;
}

struct point {int x,y;}p[2222];
bool cmp(point a,point b) {
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
ll fac[N],inv[N],dp[2222];
ll zuhe(int n,int m) {
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
	int n,m,num;  fac[0]=1; inv[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[200000]=mod_inverse(fac[200000]);
	for(int i=200000-1;i;i--) inv[i]=inv[i+1]*(i+1)%mod; 
	//cout<<zuhe(10,4)<<endl;
	
}	