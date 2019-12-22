#include<bits/stdc++.h>

using namespace std;

int bigmodof_a_power_b(int a, int b, int q)
{
    int i, x=1;

    for(i=1;i<=b;i++)
    {
        x=(x*(a%q))%q;

        cout<<x<<endl;

    }

    return x;


}

int bigmodof_n_fact(int n, int a)
{
    int x=1;

   int t;

    for(t=n;t>=1;t--)
    {
        x=(x*(t%a))%a;
        cout<<x<<endl;

    }
    return x;


}

int main()
{

//    bigmodof_n_fact(100, 97);

    int mod=bigmodof_a_power_b(2, 5, 3);

    cout<<mod<<endl;

    return 0;
}
