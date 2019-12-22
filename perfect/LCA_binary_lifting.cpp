#include<bits/stdc++.h>
using namespace std;
int n, l, timer, root;
vector<int> tin, tout;
vector<vector<int> > up, adj;
void dfs(int v, int p)
{
	tin[v]=++timer;
	up[v][0]=p;
	for(int i=1;i<=l;i++) up[v][i]=up[up[v][i-1]][i-1];
	for(int u:adj[v]) if(u!=p) dfs(u, v);
	tout[v]=++timer;
}
void preprocess()
{
	tin.resize(n+1);
	tout.resize(n+1);
	timer=0;
	up.assign(n+1, vector<int> (l+10));
	dfs(root, root);
}
bool is_ancestor(int u, int v)
{
	return tin[u]<=tin[v] and tout[u]>=tout[v];
}
int lca(int u, int v)
{
	if(is_ancestor(u, v)) return u;
	if(is_ancestor(v,u)) return v;
	for(int i=l;i>=0;i--)
		if(!is_ancestor(up[u][i], v))
			u=up[u][i];

	return up[u][0];
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	l=log2(n)+1;
	adj.assign(n+1, vector<int>(l+10));
	for(int i=1;i<n;i++)
	{
		int x, y;
		cin>>x;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>root;
	preprocess();
}
