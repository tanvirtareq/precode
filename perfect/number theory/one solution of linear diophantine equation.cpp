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

pair<int, int>  find_one_solution_of_linear_diophantine_equation(int a, int b, int c)
{
    pair<int, int> p, q;

    int g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
        cout<<"no solution"<<endl;
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

    return p;

}

int main()
{
    pair<int , int>p;
    int a, b, c;
    cin>>a>>b>>c;

    p=find_one_solution_of_linear_diophantine_equation(a, b, c);
    cout<<p.first<<" "<<p.second<<endl;


    return 0;
}

