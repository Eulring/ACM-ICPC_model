#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100009
#define f0(i,n) for(int i=0;i<(n);i++)
#define ff(i,n) for(int i=1;i<=(n);i++)
#define clr(a) memset(a,0,sizeof(a));
int Max(int a,int b){return a>b?a:b;}
double Min(double a,double b){return a<b?a:b;}
int dmin(int a,int b){return a<b?a:b;}
int Abs(int a){return a<0?-a:a;}
int gcd(int a,int b){return a%b==0? b:gcd(b,a%b);}

struct point{
  double x,y;
}a[N];
int s[N];
double dis(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}     
bool cmpx(int i,int j){return a[i].x<a[j].x;}
bool cmpy(int i,int j){return a[i].y<a[j].y;}
double min_dist(point a[],int s[],int l,int r){
  double ans=1e100;
  if(r-l<20){
    for(int q=l;q<r;q++) for(int w=q+1;w<r;w++)
    ans=Min(ans,dis(a[s[q]],a[s[w]]));
    return ans;
  }
  int tl,tr,m=(l+r)>>1;
  ans=Min(min_dist(a,s,l,m),min_dist(a,s,m,r));
  for(tl=l;a[s[tl]].x<a[s[m]].x-ans;tl++);
  for(tr=r-1;a[s[tr]].x>a[s[m]].x+ans;tr--);
  sort(s+tl,s+tr,cmpy);
  for(int q=tl;q<tr;q++)
    for(int w=1+q;w<dmin(tr,q+6);w++)
      ans=Min(ans,dis(a[s[q]],a[s[w]]));
  sort(s+tl,s+tr,cmpx);
  return ans;
}
double Min_dist(point a[],int s[],int n){
  for(int i=0;i<n;i++) s[i]=i;
  sort(s,s+n,cmpx);
  return min_dist(a,s,0,n);
}
int main()
{
  int n;
  while(scanf("%d",&n),n){
    f0(i,n) scanf("%lf%lf",&a[i].x,&a[i].y);
    printf("%.2f\n",Min_dist(a,s,n)/2);
  }
}