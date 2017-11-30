#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int mod=1e9+7;
#define ff(i,n) for(int i=1;i<=(n);i++)
#define f0(i,n) for(int i=0;i<(n);i++)
#define max(a,b) (a)>(b) ? (a):(b)
#define min(a,b) (a)<(b) ? (a):(b)
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
int m[111][111],n;
void pt(){
	ff(i,n) {
		ff(j,n) printf("%6d",m[i][j]);
		cout<<endl;
	}cout<<endl;
}
ll gcd(ll a,ll b){
	if(!(a&&b)) return 0;
	return a%b==0?b:gcd(b,a%b);}	

ll agcd(ll a,ll b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	if(a<b) swap(a,b);ll c;
	while(a%b) c=a,a=b,b=c%b;
	return b;
}


int gauss_01(){
	int j,cnt=0;
	f0(i,n){j=-1;
		if(!m[i][i]) for(j=i+1;j<n;j++)
			if(m[j][i]){ f0(k,n+1)
				swap(m[i][k],m[j][k]);
				break;
			}
		if(j==n) {cnt++;continue;};
		f0(j,n) if(m[j][i]&&j!=i) 
			f0(k,n+1) m[j][k]^=m[i][k];
	}//pt(30);
	f0(i,n) if(! m[i][i]&&m[i][n]) return 0;
	return 1<<cnt;
}

int gauss_int(){
	int j,cnt=0;
	f0(i,n){j=-1;
		if(!m[i][i]) for(j=i+1;j<n;j++)
			if(m[j][i]){ f0(k,n+1)
				swap(m[i][k],m[j][k]);
				break;
			}
		if(j==n) {cnt++;continue;};
		for(j=0;j<n;j++) if(m[j][i]&&j!=i){
			ll lcm=m[i][i]*m[j][i]/agcd(m[j][i],m[i][i]);
			ll item1=lcm/m[j][i],item2=lcm/m[i][i];
			for(int k=0;k<=n;k++) m[j][k]*=item1;
			for(int k=0;k<=n;k++) m[j][k]-=item2*m[i][k];	
		}
	}//pt();
	f0(i,n) if((m[i][i]==0)&&m[i][n]) return 0;
	return 1<<cnt;
}

#define eps 1e(-7)
int gauss_f(){


}
int main(){
	cin>>n;
	f0(i,n) f0(j,n) cin>>m[i][j];
	f0(i,n) cin>>m[i][n];
	gauss_int();
}



