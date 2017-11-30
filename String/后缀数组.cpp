#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int N = 20005;
int sa[N], rank[N], height[N];
int wa[N], wb[N], w[N], wv[N];
int n, k;
map<int,int>mp;

bool cmp(int r[], int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int r[], int sa[], int n, int m) {
    int i, j, p, *x = wa, *y = wb;
    for (i = 0; i < m; ++i) w[i] = 0;
    for (i = 0; i < n; ++i) w[x[i]=r[i]]++;
    for (i = 0; i < m; ++i) w[i] += w[i-1];
    for (i = n-1; i >= 0; --i) sa[--w[x[i]]] = i;
    for (j = 1, p = 1; p < n; j*=2, m=p) {
        for (p = 0, i = n-j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i]-j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) w[i] = 0;
        for (i = 0; i < n; ++i) w[wv[i]]++;
        for (i = 0; i < m; ++i) w[i] += w[i-1];
        for (i = n-1; i >= 0; --i) sa[--w[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}

void calheight(int r[], int sa[], int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; ++k) ;
}


int main() {
    	a[n]=0;
        da(a,sa,n+1,cnt+1);//cnt+1：数据域   a：字符串   n+1：长度为n
        calheight(a,sa,n);
        //solve();
        //for(int i=0;i<n;i++) cout<<height[i]<<endl;
    
}