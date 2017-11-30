#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#define N 4000000
typedef long long ll;
using namespace std;
inline ll vx(ll v,ll n,ll ndr,ll nv){
	return v>=ndr?(n/v-1):(nv-v);
}
ll s[N],v[N];
ll sum_prm(ll n){
	ll r=sqrt(n);
	ll nv=r+n/r-1,ndr=n/r;
	s[1]=(2+n)*(n-1)/2;

	for(int i=0;i<r;i++)
		v[i]=n/(i+1);

	for(int i=r;i<nv;i++)
		v[i]=v[i-1]-1;

	for(int i=0;i<nv;i++)
		s[i]=v[i]*(v[i]+1)/2-1;

	for(int p=2;p<=r;p++){
		if(s[nv-p]>s[nv-p+1]){
			ll sp=s[nv-p+1];
			ll p2=p*p;
			for(int i=0;i<nv;i++)
				if(v[i]>=p2)
					s[i]-=p*(s[vx(v[i]/p,n,ndr,nv)]-sp);
				else {break;}
		}
	}return s[0];
}
int main()
{
	ll x;
	while(scanf("%I64d",&x))
		cout<<sum_prm(x)<<endl;
}
