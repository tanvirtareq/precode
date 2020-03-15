#include<bits/stdc++.h>

using namespace std;

    int n;
int mdim[1000];
int tab[1000][1000];
int ans[1000][1000];

int dp(int st, int ed)
{
//    cout<<st<<ed<<endl;

    if(st<0 or st>n or ed<0 or ed>n) return INT_MAX;
    if(st==ed) return 0;

    if(tab[st][ed]!=-1) return tab[st][ed];
    int mn=INT_MAX;
    int prevmn=mn;
    int x;

    for(int i=st;i<ed;i++)
    {
        prevmn=mn;
        mn=min(mn, dp(st, i)+dp(i+1, ed)+mdim[st-1]*mdim[i]*mdim[ed]);

        if(mn<prevmn)
        {
            x=i;

        }
    }
    ans[st][ed]=x;
//    cout<<mn<<endl;

    return tab[st][ed]=mn;

}

void printAns(int st, int ed)
{

    if(st==ed)
    {
        cout<<"M"<<st;
        return;
    }
    if(st==ed-1)
    {
        cout<<"("<<"M"<<st<<"M"<<ed<<")";
        return;
    }

    else
    {
        cout<<"(";
        printAns(st, ans[st][ed]);
        printAns(ans[st][ed]+1, ed);
        cout<<")";
    }

    return;

}

/**
5
40 20 30 10 30



5
10 20 30 40 30
30000
(((M1M2)M3)M4)
*/


int main()
{
    memset(tab, -1, sizeof tab);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>mdim[i];
    }

    cout<<dp(1, n-1)<<endl;
    printAns(1,n-1);

    return 0;
}

//5 10 20 30 40 30
