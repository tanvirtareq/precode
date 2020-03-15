/**

Let us take below example to understand the solution
   num[]=number[] = {3, 4, 5}, num[] should be pairwise co-prime
   rem[]=remainder[] = {2, 3, 1}
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

int chineseRemainderTheorem(int number[], int remainder[],int n)
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


int ext_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
*/

/**
theory
https://forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/



*/



pair<int, int> chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/

    int n = A.size();

    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];

        int g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/

        /** Merge the two equations*/
        int p, q;
        ext_gcd(m1/g, m2/g, &p, &q);

        int mod = m1 / g * m2; /** LCM of m1 and m2*/

        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        int x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;

        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
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

