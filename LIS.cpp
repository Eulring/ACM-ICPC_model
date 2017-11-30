#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
const int N = 41000;  
int a[N];       //a[i] 原始数据  
int d[N];       //d[i] 长度为i的递增子序列的最小值  
  
int BinSearch(int key, int* d, int low, int high)  
{  
    while(low<=high)  
    {  
        int mid = (low+high)>>1;  
        if(key>d[mid] && key<=d[mid+1])  
            return mid;  
        else if(key>d[mid])  
            low = mid+1;  
        else  
            high = mid-1;  
    }  
    return 0;  
}  
  
int LIS(int* a, int n, int* d)  
{  
    int i,j;  
    d[1] = a[1];  
    int len = 1;        //递增子序列长度  
    for(i = 2; i <= n; i++)  
    {  
        if(d[len]<a[i])  
            j = ++len;  
        else  
            j = BinSearch(a[i],d,1,len) + 1;  
        d[j] = a[i];  
    }  
    return len;  
}  
  
int main()  
{  
    int t;  
    int n;  
    
    while(scanf("%d",&n)) {  
        for(int i = 1; i <= n; i++)  
            scanf("%d",&a[i]);  
        printf("%d\n",LIS(a,n,d));  
    }  
    return 0;  
}  