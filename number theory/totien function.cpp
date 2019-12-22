/// from 1 to n ,the number of integer that's gcd(n,x)=1 is the totien of n
#include<bits/stdc++.h>

using namespace std;

int totient(int n)
{
    int t=n;
    int ret=n;

    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
             ret=ret-ret/i;
            while(n%i==0)
            {

                n/=i;
            }
        }
    }
    return ret;
}

int main()
{
    int x=totient(120);
    cout<<x<<endl;

    return 0;
}

