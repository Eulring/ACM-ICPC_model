#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 110000
int nex[N],ls,lss;
char s[N],ss[N];
void get_nex(){
	int i=0,j=-1;nex[0]=-1;
	while(i<lss){
		if(j==-1||ss[i]==ss[j])
			nex[++i]=++j;
		else j=nex[j];	
	}	
	//for(int i=0;i<=lss;i++)
	//	cout<<nex[i]<<" "; cout<<endl;
}
void kmp(){
	int i=0,j=0;
	while(i<ls){
		if(j==-1||s[i]==ss[j])
			i++,j++;
		else j=nex[j];
		if(j==lss){
			cout<<i<<endl;
			j=nex[j];
		}
	}
}
int main()
{
	while(scanf("%s%s",s,ss)){
		lss=strlen(ss);
		ls=strlen(s);
		get_nex();
		kmp();		
	}	
}