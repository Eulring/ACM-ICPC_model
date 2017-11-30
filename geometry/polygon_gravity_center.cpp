#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define ff(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define abs(a) (a)<0 ? (-a):(a)
#define min(a,b) (a)<(b) ? (a):(b)
#define ins insert
#define pb push_back
#define N 1109000
struct point{
	double x,y;
}p[N];
double cc(point a,point b,point c){
	double x1=a.x-b.x,x2=b.x-c.x;
	double y1=a.y-b.y,y2=b.y-c.y;
	return x1*y2-x2*y1;
}
int main()
{
	int rep,n; cin>>rep;
	while(rep--){
		cin>>n;
		f0(i,n)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double x=0,y=0,sum=0;
		for(int i=2;i<n;i++){
			point p1=p[0],p2=p[i-1],p3=p[i];
			double c=cc(p1,p2,p3);
			x+=c*(p1.x+p2.x+p3.x);
			y+=c*(p1.y+p2.y+p3.y);
			sum+=c;
		} x/=sum,y/=sum;
		printf("%.2f %.2f\n",x/3,y/3);
	}
}