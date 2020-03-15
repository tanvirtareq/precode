#include<bits/stdc++.h>
using namespace std;

pair<int, int> extendedEuclidean(int a,  int b)
{
    pair<int, int> p, q;

    if(a%b==0)
    {
        p.first=0;
        p.second=1;
        return p;
    }

    q=extendedEuclidean(b, a%b);
    p.first=q.second;
    p.second=q.first+(-a/b)*q.second;
    return p;

}

pair<int, int> extendedEuclideanCover(int a, int b)
{
    pair<int, int> p;
    p=extendedEuclidean(abs(a), abs(b));



    if(a<0) p.first=-p.first;
    if(b<0) p.second=-p.second;

    return p;

}

int main()
{

    int a, b;

    while(cin>>a>>b)
    {
        a=(365-a)%365;
        b=(387-b)%387;

        pair<int, int> p1, p2;
        p1=extendedEuclideanCover(365, 387);

        int x=(p1.first+387)%387;
        int y=(p1.second+365)%365;
        cout<<(y*387)%365<<endl;

        int z=365*x*b+y*a*387;
        cout<<z<<endl;


//        cout<<z<<endl;

    }

    return 0;
}
