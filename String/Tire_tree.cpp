#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;
struct Tire{
	int v;
	Tire *next[26];
}root;
void update(char *str){
	int len=strlen(str);
	Tire *p=&root,*q;
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		if(p->next[id]==NULL){
			q=(Tire*) malloc(sizeof(Tire));
			q->v=1;
			for(int j=0;j<26;j++)
				q->next[j]=NULL;
			p->next[id]=q;
			p=p->next[id];
		}
		else {
			p->next[id]->v++;
			p=p->next[id];
		}
	}
}
int query(char *str){
	int len=strlen(str);
	Tire *p=&root ;
	for(int i=0;i<len;i++){
		int id=str[i]-'a';
		p=p->next[id];
		if(p==NULL)
			return 0; 
	}
	return p->v;
}
int main()
{
	char s[111];
	while(gets(s)&&s[0]!='\0')
		update(s);
	while(scanf("%s",s)!=EOF)
		cout<<query(s)<<endl;
}