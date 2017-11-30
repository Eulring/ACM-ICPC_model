#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=1000009;

struct point
{
    int x,y;
};
point p[MAXN];
int st[MAXN],top;

int cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2 
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}    
double dis(point p1,point p2)  //计算 p1p2的 距离 
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}    
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面 
{
    int tmp=cross(p[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(p[0],p1)<dis(p[0],p2)) return true;
    else return false;
}    
void init(int n) //输入，并把  最左下方的点放在 list[0]  。并且进行极角排序 
{
    int i,k;
    point p0;
    scanf("%d%d",&p[0].x,&p[0].y);
    p0.x=p[0].x;
    p0.y=p[0].y;
    k=0;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        if( (p0.y>p[i].y) || ((p0.y==p[i].y)&&(p0.x>p[i].x)) )
        {
            p0.x=p[i].x;
            p0.y=p[i].y;
            k=i;
        }    
    }    
    p[k]=p[0];
    p[0]=p0;
    
    sort(p+1,p+n,cmp);
}     

void graham(int n)
{
    int i;
    if(n==1) {top=0;st[0]=0;}
    if(n==2)
    {
        top=1;
        st[0]=0;
        st[1]=1;
    }    
    if(n>2)
    {
        for(i=0;i<=1;i++) st[i]=i;
        top=1;
        
        for(i=2;i<n;i++)
        {
            while(top>0&&cross(p[st[top-1]],p[st[top]],p[i])<=0) top--;
            top++;
            st[top]=i;
        }    
    }    
}    

double area(int i,int j,int k)
{
    double s=fabs(double(p[i].x*p[j].y+p[j].x*p[k].y+p[k].x*p[i].y-p[i].y*p[j].x-p[j].y*p[k].x-p[k].y*p[i].x)/2);    
    return s;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF) {
		init(n); graham(n); double ans=0,tmp;

		for(int i=0;i<=top;i++) for(int j=i+1;j<=top;j++)
			for(int k=j+1;k<=top;k++) {
				tmp=area(st[i],st[j],st[k]);
				if(tmp>ans) ans=tmp;
			}
		printf("%.2f\n",ans);	
	}
}