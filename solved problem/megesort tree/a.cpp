/**
 topic:merge sort tree
 problem: you will be given an array. for each query you will given a range and a number cap.
  you have to find how many cost you need to make the range value at least cap.

  main problem: https://toph.co/p/city-of-burgerland

*/

#include<bits/stdc++.h>
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define dbg(a) cput<<#a<<" = "<<a<<endl
#define MX 101000
#define N 510000
using namespace std;
typedef long long ll;
typedef long long unsigned lu;
typedef vector<ll> vi;
vi t[4*N];
vi tc[4*N];
ll a[N];
void build(ll n, ll b,ll e)
{
    if(b==e)
    {
        ll s=0;
        t[n].push_back(a[b]);
        for(int i=0; i<t[n].size(); i++)
        {
            s+=t[n][i];
            tc[n].push_back(s);
        }
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    ll s=0;
    merge(t[2*n].begin(), t[n*2].end(),t[2*n+1].begin(), t[2*n+1].end(),back_inserter(t[n]));
    for(int i=0; i<t[n].size(); i++)
    {
        s+=t[n][i];
        tc[n].push_back(s);
    }
    return;
}
ll query(ll n,ll b,ll e,ll i,ll j,ll k)
{
    if(b>j||e<i)
        return 0;
    if(b>=i&&e<=j)
    {
        ll s=0;
        auto it=upper_bound(t[n].begin(), t[n].end(),k);
        ll tmp=(ll)(it-t[n].begin());
        if(tmp>0)
            s+=k*tmp-tc[n][tmp-1];
        return s;
    }
    ll mid=(b+e)/2;
    return query(2*n,b,mid,i,j,k)+query(2*n+1,mid+1,e,i,j,k);
}

int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1, 1, n);
    while(m--)
    {
        ll l, r, cap;
        cin>>l>>r>>cap;
        cout<<query(1, 1, n, l, r, cap)<<endl;
    }
    return 0;
}
