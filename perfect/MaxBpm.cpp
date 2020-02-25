vi v[600];
int vis[600],match[600];
int MaxBpm(int t){
	for(int i=0;i<v[t].size();i++){
		int node=v[t][i];
		if(vis[node])continue;
		vis[node]=1;
		if(match[node]==-1 || MaxBpm(match[node])){
			match[node]=t;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin>>n>>m>>p
    for(int i=1;i<=p;i++)cin>>l[i]>>d[i];
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
            if(l[i]==d[j] || l[j]==d[i]) v[i].pb(j);
    int ct=0;
    memset(match,-1,sizeof match);
    for(int i=1;i<=p;i++){
        clr(vis);
        ct+=MaxBpm(i);
    }
    cout<<p-ct/2<<endl;
}
