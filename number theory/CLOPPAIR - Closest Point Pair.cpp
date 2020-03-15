#include<bits/stdc++.h>
#define inp(a) cin>>a.x>>a.y;
#define dist(a, b) sqrt((a.x-b.x)*(a.x-b.x)+((a.y-b.y)*(a.y-b.y)))
#define distsq(a, b) ((a.x-b.x)*(a.x-b.x)+((a.y-b.y)*(a.y-b.y)))
#define minimum(a, b) ((a.d<=b.d)?a:b)

using namespace std;

typedef long long int li;
typedef long double ld;

struct point{
li x, y;
li index;

};

struct pd{
point p, q;
li d;

};

bool cmpX(point a, point b)
{
    if(a.x<b.x) return true;

    return false;

}

bool cmpY(point a, point b)
{
    if(a.y<b.y) return true;

    return false;

}

pd merg(point strip[], li sz, pd d)
{
    pd mn=d;

    sort(strip, strip+sz, cmpY);

    for(li i=0;i<sz-1;i++)
    {
        if(distsq(strip[i], strip[i+1])<=mn.d)
        {
            mn.d=distsq(strip[i], strip[i+1]);
            mn.p=strip[i];
            mn.q=strip[i+1];
        }
        if(i+2<sz and  distsq(strip[i], strip[i+2])<=mn.d)
        {
            mn.d=distsq(strip[i], strip[i+2]);
            mn.p=strip[i];
            mn.q=strip[i+2];
        }

        if(i+3<sz and  distsq(strip[i], strip[i+3])<=mn.d)
        {
            mn.d=distsq(strip[i], strip[i+3]);
            mn.p=strip[i];
            mn.q=strip[i+3];
        }

    }

    return mn;

}

pd bruteForce(point p[], li n)
{
    pd mn;
    mn.d=LLONG_MAX;

    for(li i=0;i<n-1;i++)
    {
        for(li j=i+1;j<n;j++)
        {
            if(mn.d>=distsq(p[i], p[j]))
            {
                mn.d=distsq(p[i], p[j]);
                mn.p=p[i];
                mn.q=p[j];
            }
        }
    }

    return mn;

}

pd closestpair(point p[], li n)
{

    if(n<=3)
    {
        return bruteForce(p, n);
    }

    li mid=n/2;

    pd dr=closestpair(p, mid);
    pd dl=closestpair(p+mid,n-mid);

    pd d=minimum(dr, dl);

    point strip[n];

    li j=0;

    for(li i=0;i<n;i++)
    {
        if(abs(p[i].x-p[mid].x)<d.d)
        {
            strip[j++]=p[i];
        }

    }

    return minimum(d, merg(strip, j, d));

}

int main()
{
    li n;

    cin>>n;

    point p[n+10];

    for(li i=0;i<n;i++){
        inp(p[i]);
        p[i].index=i;

    }

    pd ans=closestpair(p, n);

    cout<<min(ans.p.index, ans.q.index)<<" "<<max(ans.q.index, ans.p.index)<<" ";
    printf("%.6Lf\n", sqrtl((ld)ans.d));

    return 0;
}




