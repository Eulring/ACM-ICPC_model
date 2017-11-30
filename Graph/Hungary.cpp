#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
#define N 122222
#define ff(i,n) for(int i=1;i<=(n);i++) 
#define f0(i,n) for(int i=0;i<(n);i++)
int vis[N],mat[N];
vector<int> e[444];

int crosspath(int k){
    for(int i=0;i<e[k].size();i++){
        int j=e[k][i];    
        if(!vis[j]){
            vis[j]=1;
            if(mat[j]==-1||crosspath(mat[j]))
                {mat[j]=k;return 1;}                        
        }            
    }return 0;
}
void hungary(int num){
    memset(mat,-1,sizeof(mat)); 
    int match=0;
    for(int i=1;i<=num;i++){
        memset(vis,0,sizeof(vis));    
        if(crosspath(i)) match++;    
    }
}

int main()
{
	
}