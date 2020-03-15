#include<bits/stdc++.h>

using namespace std;

int sz, maxLavel;

vector<int> child[1000];

int parent[1000];
int sparseTable[1000][(int)log2(20)];
int level[1000];


void inputGraph()
{
    int n;
    cin>>n;

    sz=n;
    for(int i=1; i<=n; i++)
    {
        int m;
        cin>>m;

        while(m--)
        {
            int a;
            cin>>a;

            child[i].push_back(a);
            parent[a]=i;
        }

    }

}

int findRoot()
{
    for(int i=1;i<=sz;i++)
    {
        if(parent[i]==0) return i;

    }

}

void dfs(int rt, int l)
{
    level[rt]=l;
    maxLavel=max(maxLavel, l);

    for(int i=0;i<child[rt].size();i++)
    {
        if(level[child[rt][i]]==0)
        {
            dfs(child[rt][i], l+1);
        }

    }

}

void findLavel()
{
    int root=findRoot();

    dfs(root, 0);

}

void makeSparseTable()
{
    int x=log2(maxLavel);

    for(int i=0;i<=x;i++)
    {
        for(int j=1;j<=sz;j++)
        {
            if(i==0)
            {
                sparseTable[j][i]=parent[j];
            }
            else
            {
                sparseTable[j][i]=sparseTable[sparseTable[j][i-1]][i-1];


            }
        }

    }

}

int findAinBlevel(int a, int b)
{
    int x=log2(maxLavel);
    while(x>=0)
    {
        if(sparseTable[a][x]!=0 and level[sparseTable[a][x]]>=level[b])
            a=sparseTable[a][x];

        x--;
    }

    return a;
}

int lca(int a, int b)
{
    if(level[a]<level[b])
        swap(a, b);

    a=findAinBlevel(a, b);

    int x=log2(maxLavel);

    while(x>=0)
    {
        if(sparseTable[a][x]!=sparseTable[b][x])
        {
            a=sparseTable[a][x];
            b=sparseTable[b][x];
        }
        x--;

    }

    return sparseTable[a][0];

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        inputGraph();
        findLavel();
        makeSparseTable();

        int q;
        cin>>q;
        while(q--)
        {
            int a, b;
            cin>>a>>b;
            cout<<lca(a,b)<<endl;

        }
    }

}
