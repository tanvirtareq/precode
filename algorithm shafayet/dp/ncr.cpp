#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[10000][10000];


int ncr(int n, int r)
{
    if(dp[n][r]!=0)
    {
        cout<<n<<" "<<r<<" is saved as "<<dp[n][r]<<endl;
        return dp[n][r];
    }
    else if(n==r)
    {
        return 1;
    }
    else if(r==1)
    {
        return n;
    }

    dp[n][r]=ncr(n-1, r)+ncr(n-1, r-1);

    cout<<n<<" "<<r<<" will save as "<<dp[n][r]<<endl;

    return dp[n][r];

}

int main()
{
    memset(dp, 0, 10);


    cout<<ncr(7, 4);

	return 0;
}




