bool bfs()
{
    int f = 0 , b = 0 , i ;
    for(i=1;i<=n;i++)
    {
        if( match[i] == 0 )
        {
            dist[i] = 0 ;
            q[f++] = i ;
        }
        else dist[i] = INF ;
    }
    dist[0] = INF ;
    while( b < f )
    {
        int x = q[b++] ;
        if( x == 0 ) continue ;
        int sz = adj[x].size();
        for(i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == INF )
            {
                dist[match[y]] = dist[x] + 1 ;
                q[f++] = match[y];
            }
        }
    }
    cout << INF <<" " << dist[0] << endl;
    return dist[0] != INF ;
}
bool dfs(int x)
{
    if( x )
    {
        int sz = adj[x].size();
        for(i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == dist[x] + 1 && dfs(match[y]))
            {
                match[x] = y ;
                match[y] = x ;
                return 1 ;
            }
        }
        dist[x] = INF ;
        return 0 ;
    }
    return 1 ;
}
int hopcropt()
{
    int matching = 0 ;
    while( bfs() )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            if( match[i] == 0 && dfs(i) )
            {
                matching++;
            }
        }
        cout << matching << endl;
    }
    return n - matching ;
}
int main()
{
   hopcropt());
    return 0;
}
