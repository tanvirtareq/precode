#include<bits/stdc++.h>

using namespace std;
int n;
int tab[1000][1000];
int ar[1000];
vector<int> v;

int printLis(int st, int lst, int took)
{
//    cout<<st<<" "<<lst<<" "<<took<<endl;

    if(st>n) return tab[st][lst]=took;
//    if(st==n)

    if(tab[st][lst]!=-1)  return tab[st][lst];
    int p=-1;
    if( lst==0 or  ar[st]>ar[lst])
        p=printLis(st+1, st, took+1);

    int q=printLis(st+1, lst, took);

//    cout<<st<<" "<<lst<<" "<<took<<endl;
//    cout<<tab[st+1][lst]<<" "<<tab[st+1][st]<<endl;

//    if(p>q) v.push_back(ar[st]);

    return tab[st][lst]=max(p, q);

}

void printAns(int st, int lst)
{
//    cout<<st<<lst<<endl;
    if(st>n+1) return ;
//    cout<<tab[st+1][st]<<endl;

//    if(lst==0)
//    {
//
//    }


    if(tab[st+1][lst]<=tab[st+1][st])
    {
        cout<<ar[st]<<endl;
        printAns(st+1, ar[st]);
        return ;
    }

    printAns(st+1, lst);
    return;
}

int main()
{

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    memset(tab, -1, sizeof tab);

    printLis(1, 0, 0);

    cout<<tab[2][0]<<" "<<tab[2][1]<<endl;

//    reverse(v.begin(), v.end());

    printAns(1, 0);

//    for(int i=0;i<v.size();i++)
//    {
//        cout<<v[i]<<" ";
//    }

    return 0;
}

