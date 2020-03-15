#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int hackenbush(int u, int parent)
{
    int result = 0;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == parent)
            continue;
        result ^= hackenbush (v, u) + 1;
    };
    return result;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int rs=hackenbush(1, 0);
    if(rs)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;

}
