#include<bits/stdc++.h>
#define inp_ar(ar, s, e) for(int i=s;i<=e;i++) cin>>ar[i]
#define print_ar(ar, s, e) for(int i=s;i<=e;i++) cout<<ar[i]<<endl

using namespace std;

int func(int a, int b)
{
    return min(a, b);

}

void inline make_sparse_table(int s, int e, int mxn,  int ar[], int spTable[][1000])
{
    memset(spTable, 0, sizeof spTable);

    for(int i=1;i<=e;i++)
    {
        spTable[i][0]=ar[i];
        cout<<spTable[i][0]<<endl;

    }

    for(int j=1;j<mxn;j++)
    {
        for(int i=1;i+(1<<(j-1))<=e;i++)
        {
            spTable[i][j]=func(spTable[i][j-1], spTable[i+(1<<(j-1))][j-1]);
            cout<<spTable[i][j]<<endl;
        }

    }
    return;
}

void print_2d(int ar[][1000], int n, int mxn)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=mxn;j++)
    {
        cout<<ar[i][j]<<" ";
    }
    cout<<endl;

}

int find_(int spTable[][1000], int p, int q)
{
    if(p>q) return INT_MAX;

    if(p==q) return spTable[p][0];
    int range=q-p+1;
    int j=floor((double)log2(range));
//    cout<<spTable[p][j]<<endl;

    return func(spTable[p][j], find_(spTable,p+(1<<j), q));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    int ar[n+10];

    inp_ar(ar, 1, n);
    int mxn=floor((double)log2(n));

    int spTable[n+10][1000];

    make_sparse_table(1, n, mxn, ar, spTable);

    int p, q;
    while(cin>>p>>q)
    {
        cout<<find_(spTable, p, q)<<endl;

    }



    return 0;
}

/**

8
2 4 7 1 5 3 6 8

*/


