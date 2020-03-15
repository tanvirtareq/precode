#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int napsac(int i,int befw, int w[], int p[], int n, int cap)
{
//    if(dp[i][befw]!=-1)
//    {
//        return dp[i][befw];
//    }

    if(i==n+1)
    {
//        dp[i][befw]=befp+p[i];
        return 0;
    }

    if(befw+w[i]>cap)
    {
        //dp[i][befw]=napsac(i+1, befw, befp);

        int x=napsac(i+1, befw, w, p, n, cap);

        cout<<" if  do not take "<<i<<"th product maximum can be "<<x<<endl;

        return x;
    }
    else
    {
        int x=p[i]+napsac(i+1, befw+w[i], w, p, n, cap);
         cout<<" if  take "<<i<<"th product maximum can be "<<x<<endl;

         int y=napsac(i+1, befw, w, p, n, cap);

         cout<<" if  do not take "<<i<<"th product maximum can be "<<y<<endl;

        return max(x, y);
    }

}

int main()
{
    int n, cap;

    cin>>n>>cap;

    int p[n+10], w[n+10];

    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>p[i];
    }

    int dp[n+10][cap+10];

    cout<<napsac(1, 0, w, p, n, cap)<<endl;

	return 0;
}

/**
5 10
1 120
7 400
4 280
3 150
4 200



*/



