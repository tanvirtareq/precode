/// from 1 to n ,the number of integer that's gcd(n,x)=1 is the totien of n
/**
n=p1^(a1)*p2^(a2)*...pk^(ak)
then phi(n)=n*(p1-1)/p1*(p2-1)/p2*...(pk-1)/pk

*/

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



/// this function will pre calculate phi of 1 to n in O(n) complexity
int lp[MX + 10];
int phi[MX + 10];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= MX; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MX; ++j)
            lp[i * pr[j]] = pr[j];
    }
}



/// rhis will pre calculate phi of 1 to n in O(nlogn) complexity
ll p[MX+10], g[MX+10];

void precalphi()
{
    for(int i=1;i<=MX;i++) p[i]=i;

    for(ll i=2;i<=MX;i++)
    {
        if(p[i]==i)
        {
            for(ll j=i;j<=MX;j+=i)
            {
                p[j]=p[j]/i*(i-1);
            }
        }
    }
}


/// this will precalculate all pair gcdsum for 1 to n in O(nlogn) complexity
void gcdx()
{
    for(ll i=2;i<=MX;i++) g[i]=phi[i];

    for(ll i=2;i<=MX;i++)
    {

            for(ll j=i+i;j<=MX;j+=i)
            {
                g[j]+=j*phi[i]/i;
            }
    }

    for(ll i=2;i<=MX;i++) g[i]+=g[i-1];
}


int main()
{
    int x=totient(120);
    cout<<x<<endl;

    return 0;
}

