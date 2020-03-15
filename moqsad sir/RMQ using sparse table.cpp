#include<bits/stdc++.h>

using namespace std;

int sparseTable[1000][20];

void makeSparseTable(int ar[], int sz)
{
    int x=log2(sz);

    int z=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=1;j<=sz;j++)
        {
            if(i==0)
            {
                sparseTable[j][i]=ar[j];
            }

            else
            {
                if((1<<(i-1))+j>sz) break;

                sparseTable[j][i]=min(sparseTable[j][i-1], sparseTable[j+(1<<(i-1))][i-1]);

            }

            cout<<sparseTable[j][i]<<" ";

        }
        z*=2;

        cout<<endl;

    }



}

int RMQ(int a,int b)
{
    cout<<a<<" "<<b<<endl;

    if(a==b) return sparseTable[a][0];

    int number=b-a+1;

    int lv=log2(number);

    int lp=1<<lv;

    int ret;

    if(b==a+lp-1)
        ret= sparseTable[a][lv];


else
    ret= min(sparseTable[a][lv], RMQ(a+lp, b));

    cout<<ret<<endl;

    return ret;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        cin>>n>>q;

        int ar[n+10];

        for(int i=1;i<=n;i++)
            cin>>ar[i];

        makeSparseTable(ar, n);

        while(q--)
        {
            int a, b;
            cin>>a>>b;

            cout<<RMQ(a, b)<<endl;

        }


    }


}

/**
10
9 10
1 2 1 0 3 2 5 7 3

*/
