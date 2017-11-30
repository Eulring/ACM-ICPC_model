#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

struct cmp1{
	bool operator () (int &a,int &b) {return a<b;}
};
struct cmp2{
	bool operator () (int &a,int &b) {return a>b;}
};
struct cmp3{
	bool operator () (int &a,int &b) {return a%10<b%10;}
};
struct number{ int x;   
	bool operator < (const number &a) const{
		return x%9>a.x%9;
	}
};
priority_queue<int> q1;
priority_queue<int,vector<int>,cmp3> q3;

priority_queue<int,vector<int>,greater<int> > q;
priority_queue<int,vector<int>,less<int> > q8;
priority_queue<number> q7;

void test(){
	for(int i=1;i<=35;i++) q.push(i);
	while(!q.empty()) cout<<q.top()<<endl,q.pop();	
}
void test2(){
	number tmp;
	//for(int i=1;i<=34;i++) tmp.x=i,q.push(tmp);
	//while(!q.empty()) cout<<q.top().x<<endl,q.pop();		
}


int main()
{
	test();
}