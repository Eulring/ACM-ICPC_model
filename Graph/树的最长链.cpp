//求树的最长链的两种方法
void dfs(int pre,int u,int len){
    //cout<<pre<<" "<<u<<endl;
    //cin>>len;
    if(len>maxlen){
        maxlen=len;
        ep=u;
    }
    for(int i=head[u];i+1;i=e[i].next){
        int to=e[i].to;
        if(pre==to) continue;
        dfs(u,to,len+1);
    }
}
maxlen=-1; dfs(-1,0,0);
maxlen=-1; dfs(-1,ep,0);




int dfs(int u,int pre)
{
    int tmp = 0;
    for(int i=head[u];i+1; i=e[i].next )
    {
        int v = e[i].to;
        if( v == pre ) continue;

        int d = dfs(v,u);
        maxlen = max( maxlen, tmp+d );
        tmp = max(tmp,d);
    }
    return tmp+1;
}
maxlen=-1; dfs(0,-1);