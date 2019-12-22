#include<bits/stdc++.h>

using namespace std;

void bit_pattern(int n)
{
//    cout<<sizeof(n)<<endl;
    for(int i=8*sizeof(n);i>=1;i--)
    {
        if(n&(1<<(i-1))) cout<<"1";
        else cout<<"0";
    }
    cout<<endl<<endl;

}

int copy_by_mask(int x, int mask)
{
    int b=x&mask;
    return b;

}

int masking(int i, int j)
{
    int x=0;
    bit_pattern(x);
    for(int k=i;k<=j;k++)
    {
        x=x|(1<<(k-1));
        bit_pattern(x);
    }
//    x=x<<(i-1);
    bit_pattern(x);

    return x;
}

int main()
{
    int x=masking (3, 5);
//    int n;
////    while(cin>>n)
////        bit_pattern(n);
//
        int a=5;
        bit_pattern(a);

        int b=copy_by_mask(a, x);
        cout<<b<<endl;
//
////        if(!(a&1)) cout<<"even"<<endl;
//    int b=2;
//
////        cout<<(a<<1)<<endl;
//
        bit_pattern(b);
//
//        cout<<(a^b)<<endl;
//        bit_pattern(a^b);

    return 0;
}

