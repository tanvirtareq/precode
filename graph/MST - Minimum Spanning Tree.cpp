#include<bits/stdc++.h>


using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli, lli> pii;
typedef pair<lli, pii> pipii;

lli n, m, x, y;

   lli p[101000];

int inline fanc(lli a)
{
    if(p[a]==a) return a;
    return fanc(p[a]);
}

void inline makeanc(lli a, lli b)
{
    if(p[a]==a) p[a]=b;

    else
    {
        makeanc(min(p[a], b), max(p[a], b));
    }

    return;

}


int main()
{

    cin>>n>>m;

    priority_queue<pipii , vector<pipii> , greater<pipii> >pq;

    while(m--)
    {
        lli x, y, w;
        cin>>x>>y>>w;

        pq.push(make_pair(w, make_pair(min(x, y), max(x, y))));
    }

    lli s=0;

    lli cost=0;



    for(lli i=1;i<=n;i++)
    {
        p[i]=i;
    }

    while(s!=n-1)
    {
        lli c=pq.top().first;

        lli a=pq.top().second.first;
        lli b=pq.top().second.second;

        pq.pop();

        if(fanc(a)==fanc(b)) continue;

        makeanc(a, b);

        s++;
        cost+=c;

    }

    cout<<cost<<endl;



    return 0;
}

/**

8 10
1 5
1 4
1 2
2 3
2 4
3 4
4 5
4 7
4 8
6 7
6 8

*/

