#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
struct point{
  double x,y;
}p[55555],st[55555];
double Min(double a,double b){return a<b?a:b;}
double Max(double a,double b){return a>b?a:b;}
void Swap(point &a,point &b){point c=a;a=b;b=c;}
int  top;
int s[55555];

int cmp(double x){
  if(fabs(x)<eps) return 0;
  if(x>0) return 1;
  return -1;
}
double edis(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
double det(point a,point b,point c){
  return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);}
bool cmp1(point a,point b){
  if(det(a,b,p[0])>0) return 1;
  if(det(a,b,p[0])==0&&edis(a,p[0])<edis(b,p[0])) return 1;
  return 0;
}
bool cmpx(int i,int j){
  return cmp(p[i].x-p[j].x)<0;}
bool cmpy(int i,int j){
  return cmp(p[i].y-p[j].y)<0;}

void graham(int n){
  int  ld=0;
  for(int i=1;i<n;i++)
    if(p[i].y<p[ld].y)
      ld=i;
    else if(p[i].y==p[ld].y&&p[i].x<p[ld].x)
      ld=i;
  //cout<<ld<<endl;    
  Swap(p[ld],p[0]);
  sort(p+1,p+n,cmp1);
  
  st[0]=p[0];st[1]=p[1];//st[2]=p[2];
  top=1;
  for(int i=2;i<n;i++){
    while(top>=1&&det(st[top-1],st[top],p[i])<0)
      top--;
    st[++top]=p[i];
  }//cout<<1<<endl;
}

double min_dist(point a[],int s[],int l,int r){
  double ans=1e100;
  if(r-l<20){
    for(int q=l;q<r;q++)
    for(int w=q+1;w<r;w++)  ans=Min(ans,edis(a[s[q]],a[s[w]]));
    return ans;
  }
  int tl,tr,m=(l+r)/2;
  ans=Min(min_dist(a,s,l,m),min_dist(a,s,m,r));
  for(tl=l;a[s[tl]].x<a[s[m]].x;tl++);
  for(tr=r-1;a[s[tr]].x>a[s[m]].x+ans;tr--);
  sort(s+tl,s+tr,cmpy);
  for(int q=tl;q<tr;q++)
    for(int w=q+1;w<Min(tr,q+6);w++)
      ans=Min(ans,edis(a[s[q]],a[s[w]]));
  sort(s+tl,s+tr,cmpx);
  return ans;
}
double Min_dist(point a[],int n){
  int s[55555];
  for(int i=0;i<n;i++) s[i]=i;
  sort(s,s+n,cmpx);
  return min_dist(a,s,0,n);
}

int main()
{
  int n,cas=0;
  while(scanf("%d",&n)&&n){
    for(int i=0;i<n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    graham(n);//cout<<1;
    double mindist=Min_dist(p,n);
    double maxdist=0;
    //cout<<top<<endl;
    //for(int i=0;i<top;i++)
      //printf("%.0f %.0f\n",st[i].x,st[i].y);
    for(int i=0;i<=top;i++)
      for(int j=i+1;j<=top;j++)
        maxdist=Max(maxdist,edis(st[i],st[j]));
    printf("Case %d:\n",++cas);
    printf("Distance of the nearest couple is %.3f\n",sqrt(mindist));
    printf("Distance of the most distant couple is %.3f\n",sqrt(maxdist));
    cout<<endl;
  }
}