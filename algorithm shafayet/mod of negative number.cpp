#include<bits/stdc++.h>

using namespace std;

int modof_neg_or_positive_number(int n, int a)
{
    int q=floor((double)n/a);

   int  r=n-a*q;

//    int r=(n%a+a)%a;

    cout<<r<<endl;
    return r;


}

int main()
{
    int n, a;
   while( cin>>n>>a)

    modof_neg_or_positive_number(n, a);

    return 0;
}

