/**

Let us take below example to understand the solution
   num[]=number[] = {3, 4, 5}, rem[]=remainder[] = {2, 3, 1}
   prod=productOfAllNumber  = 60
   pp[]  = {20, 15, 12}  { productOfAllNumber/number[i] };
   inv[]=modularMultiplicativeInverse[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
                        // (12*3)%5 = 1

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
        rem[2]*pp[2]*inv[2]) % prod
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     = (40 + 135 + 36) % 60
     = 11


     */


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

chineseRemainderTheorem(int number[], int remainder[],int n)
{
    int product=1;

    int x=0;

    for(int i=0;i<n;i++)
        product*=number[i];

    int pp[n+10];

    for(int i=0;i<n;i++){

        int pp=product/number[i];

        int modInv=modularMultiplicativeInverse(pp, number[i]);

        x+=pp*modInv*remainder[i];
    }

    return x%product;
}

int main()
{

    int n;

    cin>>n;

    int number[1000], remainder[1000];
    memset(number ,0, sizeof number);
    memset(remainder, 0, sizeof remainder);

    for(int i=0;i<n;i++)
        cin>>number[i];

    for(int i=0;i<n;i++)
        cin>>remainder[i];


    cout<<chineseRemainderTheorem(number, remainder, n)<<endl;

    return 0;
}

