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

int modularMultiplicativeInverse(int a, int m)
{
    pair<int,  int> p=extendedEuclideanCover(a, m);

    if(p.first<0) p.first+=m;
    return p.first;

}

int main()
{

    int a, m;

    while(cin>>a>>m)
    {
        cout<<modularMultiplicativeInverse(a, m)<<endl;
    }

    return 0;
}

