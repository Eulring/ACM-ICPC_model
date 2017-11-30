#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define N 11111
typedef long long ll;
ll mod=1000000007;
ll ni[N];
ll qp(ll x,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans*=x,ans%=mod;
		n>>=1; x*=x; x%=mod;
		//cout<<x<<" "<<ans<<endl;
	}return ans;
}
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
ll zuhe(ll n,ll m){
	ll ans=1;
	for(ll i=n-m+1;i<=n;i++)
		ans*=i,ans%=mod;
	for(ll i=1;i<=m;i++)
		ans*=ni[i],ans%=mod;
	return ans;
}

int main()
{
}