#include<bits/stdc++.h>

using namespace std;

typedef long long int llu;

llu bigmodf(llu b, llu p, llu m)
{
    if(p==0) return 1;
    else if(p==1) return b%m;

    else if(p%2==0)
    {

        llu x=bigmodf(b, p/2, m);

        return (x*x)%m;
    }

    else
    {
        llu x=bigmodf(b, (p-1)/2, m);
        return ((b%m)*x*x)%m;
    }

}

int main()
{
    while(1)
    {
        llu b, p, m;
        cin>>b>>p>>m;
        cout<<bigmodf(b, p, m)<<endl;
    }

    return 0;
}
