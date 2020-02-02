/// from 1 to n ,the number of integer that's gcd(n,x)=1 is the totien of n
#include<bits/stdc++.h>

using namespace std;

ll totient(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main()
{
    int x=totient(120);
    cout<<x<<endl;

    return 0;
}

