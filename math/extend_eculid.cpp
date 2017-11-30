#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
void ext_ecld(int pv,int v){
	int flag=0;
	if(pv<v) swap(pv,v),flag=1;
	int px=1,py=0,x=0,y=1;
	while(pv%v){
		px-=(pv/v)*x; swap(px,x);
 		py-=(pv/v)*y; swap(py,y);
 		pv=pv%v; swap(pv,v);
	}
	if(flag) swap(x,y);
	cout<<x<<" "<<y<<endl;

}

int main()
{
	int a,b,x,y;
	while(scanf("%d%d",&a,&b))
		ext_ecld(a,b);
}