#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define N 1009
using namespace std;

//f[]：可以取走的石子个数
//sg[]:0~n的SG函数值
//hash[]:mex{}
int f[N],sg[N],hash[N];     
void getSG(int n)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(hash,0,sizeof(hash));
        for(j=1;f[j]<=i;j++)
            hash[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)    //求mes{}中未出现的最小的非负整数
        {
            if(hash[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}

//注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合s的大小 S[i]是定义的特殊取法规则的数组
int s[110],sg[10010],n;
int SG_dfs(int x)
{
    int i;
    if(sg[x]!=-1)
        return sg[x];
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(x>=s[i])
        {
            SG_dfs(x-s[i]);
            vis[sg[x-s[i]]]=1;
        }
    }
    int e;
    for(i=0;;i++)
        if(!vis[i])
        {
            e=i;
            break;
        }
    return sg[x]=e;
}




int sg[N],m;
int get_sg(int n){
	//一条链中取连续m段 
	//if g=g1+g2+...gn   sg[g]=sg[g1]^sg[g2]^...sg[gn]
	//sg值为所有后继点的mex(表示最小的不属于这个集合的非负整数)值 
	if(sg[n]>=0) return sg[n];
	if(n-m<0) return sg[n]=0;
	bool vis[N]={0};
	for(int i=0;i<=n-m;i++)
		vis[get_sg(i)^get_sg(n-m-i)]=1;
	for(int i=0;;i++)
		if(!vis[i]) return sg[n]=i;	
}






int main()
{
	int rep,n,cas=0; cin>>rep;
	while(rep--) {
		scanf("%d%d",&n,&m);
		memset(sg,-1,sizeof(sg));
		printf("Case #%d: ",++cas);
		if(n<m||get_sg(n-m)) puts("abcdxyzk");
		else puts("aekdycoin");
	}
}