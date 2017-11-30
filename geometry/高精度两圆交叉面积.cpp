#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <complex>
#include <stack>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <set>

using namespace std;
#define   N            201009
#define   f0(i,n)      for(int (i)=0;(i)<(n);(i)++)
#define   ff(i,n)      for(int (i)=1;(i)<=(n);(i)++)
#define   clr(a,b)     memset((a),(b),sizeof((a)))
#define   lson         rt<<1
#define   rson         rt<<1|1
#define   X            first 
#define   Y            second
#define   m_p          make_pair
#define   p_b          push_back
#define   sq(a)        (a)*(a) 
#define   INF          1<<30

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const double PI=acos(-1);


struct cir{ld x,y,r;}c1,c2;
ld area(cir x){
	return PI*x.r*x.r;
};
int connection() {
	ld dis=abs(point(c1.x, c1.y) - point(c2.x, c2.y));
	if(dis+c1.r<=c2.r) return 1;
	if(dis+c2.r<=c1.r) return 1;
	if(dis>=c1.r+c2.r) return 0;
	return -1;
}
ld c_area() {
	ld d = abs(point(c1.x, c1.y) - point(c2.x, c2.y));
	ld r1=c1.r,r2=c2.r;
	ld g1 = 2 * acos(((r1 - r2) * (r1 + r2) + sq(d)) / (2.0 * r1 * d));
	ld g2 = 2 * acos(((r2 - r1) * (r1 + r2) + sq(d)) / (2.0 * r2 * d));
	ld d1 = (sq(r1) * (g1 - sin(g1))) / 2.0;
	ld d2 = (sq(r2) * (g2 - sin(g2))) / 2.0;
	ld dd = d1 + d2; return dd;
}
int main()
{
	
	cin>>c1.x>>c1.y>>c1.r;
	cin>>c2.x>>c2.y>>c2.r;
	ld ans;
	int con=connection(); //cout<<con<<endl;
	if(con==1) 
		ans=min(area(c1),area(c2));
	else if(con==0) 
		ans=0;
	else ans=c_area(); 
	cout<<setprecision(10)<<ans<<endl;	
}

 