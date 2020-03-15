#include<bits/stdc++.h>
#define pb(a) push_back(a)

using namespace std;

vector<int> eulerCircuitDirectedGraph(vector<int> v[], int rt)
{
//    cout<<rt<<"as "<<v[rt].size()<<endl;


    vector<int> path, temp;

    if(v[rt].size()==0) return path;

    int vis[1000]={0};

    int ch=v[rt].back();
    int prev=rt;

    temp.push_back(rt);
    temp.push_back(ch);

    while(ch!=rt)
    {
        if(v[ch].size()>1) vis[ch]=1;
        else vis[ch]=0;

        v[prev].pop_back();
        prev=ch;
        ch=v[ch].back();
        temp.push_back(ch);

    }
//    temp.push_back(ch);
//    cout<<"temp"<<endl;
//     for(int i=0;i<temp.size();i++)
//    {
//
//        cout<<temp[i]<<endl;
//
//    }
//    cout<<"temp nd "<<endl;


    for(int i=0;i<temp.size();i++)
    {
        ch=temp[i];
        if(vis[ch]==1 && ch!=rt)
        {
            vector<int > ans=eulerCircuitDirectedGraph(v, ch);
//            cout<<ans.size()<<endl;
            for(int j=0;j<ans.size();j++)
            {
                path.push_back(ans[j]);

            }
            if(ans.size()==0) path.push_back(ch);

        }
        else
        {
            path.push_back(ch);

        }

    }
    return path;
}

vector<int> eulerCircuit(vector<int> v[], int rt)
{

    vector<int> path, temp;

    if(v[rt].size()==0) return path;

    int vis[1000]={0};

    int ch=v[rt].back();
    int prev=rt;

    temp.push_back(rt);
    temp.push_back(ch);

    while(ch!=rt)
    {
        if(v[ch].size()>2) vis[ch]=1;
        else vis[ch]=0;

        v[prev].pop_back();

        auto it=find(v[ch].begin(), v[ch].end(), prev);


        v[ch].erase(it);

        prev=ch;
        ch=v[ch].back();
        temp.push_back(ch);


    }


    for(int i=0;i<temp.size();i++)
    {
        ch=temp[i];
        if(vis[ch]==1 && ch!=rt)
        {
            vector<int > ans=eulerCircuit(v, ch);
//            cout<<ans.size()<<endl;
            for(int j=0;j<ans.size();j++)
            {
                path.push_back(ans[j]);

            }
            if(ans.size()==0) path.push_back(ch);

        }
        else
        {
            path.push_back(ch);

        }

    }
    return path;
}

vector<int> eulerCircuit(map<int, map<int, int> > uv, int rt)
{
    vector<int> path;

    int vis[1000]={0};
    int ch;
    for(auto it=uv[rt].begin();it!=uv[rt].end();it++)
    {
        if(it->second==1)
        {
            ch=it->first;
            break;
        }

    }

}

int main()
{

    vector<int> v[1000], directed[1000];

    int n,e;

    cin>>n>>e;

    map<int , map<int , int> > uv;

    for(int i =1;i<=e;i++)
    {
        int x, y;
        cin>>x>>y;

        v[x].pb(y);
        v[y].pb(x);

    }

//    vector<int> ans=eulerCircuit(uv, 1);
    vector<int> ans=eulerCircuit(v, 1);

     for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i]<<endl;

    }


    return 0;
}

/**

7 10
1 2
2 7
2 3
3 4
4 5
4 2
5 7
6 4
7 1
7 6

*/

