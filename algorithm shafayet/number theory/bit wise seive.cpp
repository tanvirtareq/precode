#include<bits/stdc++.h>

using namespace std;

#define bit 64

int pr[bit/32];

void setp(int n, int pos)
{
    pr[n/32]&=(1<<pos);
    return;
}

void bitwise_seive()
{

    for(int i=0;i<bit/32;i++)
    {
         pr[i]|=(-1);
    }
    for(int i=0;i<=32;i++)
    {
        cout<<(pr[0]&(1<<i));
    }
    setp(1, 2);



}

int main()
{
    bitwise_seive();

    return 0;
}
