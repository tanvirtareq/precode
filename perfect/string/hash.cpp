#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 1100000
using namespace std;

ii pw[N], invpw[N];
const int p1=137, p2=277;
const int MOD1=127657753, MOD2=987654319;
int invp1, invp2;

ll qpow(ll n, ll k, ll mod)
{
    ll ans =1;
    assert(k>0);
    n%=mod;
    while(k>0)
    {
        if(k&1)
            ans=(ans*n)%mod; n=(n*n)%mod; k>>=1;
    }
    return ans%mod;
}
void pre()
{
    pw[0]= {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first=1LL*pw[i-1].first*p1%MOD1;
        pw[i].second=1LL*pw[i-1].second*p2%MOD2;
    }

    invp1=qpow(p1, MOD1-2, MOD1);
    invp2=qpow(p2, MOD2-2, MOD2);
    invpw[0]= {1, 1};
    for(int i=1; i<N; i++)
    {
        invpw[i].first=1LL*invpw[i-1].first*invp1%MOD1;
        invpw[i].second=1LL*invpw[i-1].second*invp2%MOD2;
    }
}

struct RollingHash
{
    int n;
    string s;/// 0-indexed
    vector<ii> hs;/// 1- indexed
    void init(string _s)
    {
        n=_s.size();
        s=_s;
        hs.push_back({0, 0});
        for(int i=0; i<n; i++)
        {
            ii p;
            p.first=(hs[i].first+1LL*pw[i].first*s[i]%MOD1)%MOD1;
            p.first=(hs[i].first+1LL*pw[i].first*s[i]%MOD1)%MOD1;
            hs.push_back(p);
        }
    }

    /// returns hash of substring [l....r], 1-indexed
    ii get_hash(int l, int r)
    {
        ii ans;
        ans.first=(hs[r].first-hs[l-1].first+MOD1)%MOD1*1LL*invpw[l-1].first%MOD1;
        ans.second=(hs[r].second-hs[l-1].second+MOD2)%MOD2*1LL*invpw[l-1].second%MOD2;
        return ans;
    }
};

RollingHash h;



int main()
{
    int i, j, k, n, m;
    /// never forget to initialize pre()
    pre();
    string s;
    cin>>s;
    h.init(s);
    while(1)
    {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        cout<<(h.get_hash(a, b)==h.get_hash(c, d))<<endl;
    }

}
