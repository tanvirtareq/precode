#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;

bool ar[1000];
vector<int>v;

int nOfD(int g)
{
    if(mp[g]!=0) return mp[g];
    int n=0;
    for(int i=1;i*i<=g;i++)
    {
        if(i*i==g) n++;
        else if(g%i==0) n+=2;
    }
    return n;
}

int cd(int n)
{
    if(n==1)
    {
        mp[n]=0;
//        cout<<"n="<<n<<" mp[n]"<<mp[n]<<endl;
        return 0;
    }
    else if(mp[n]!=0)
    {
//        cout<<"n="<<n<<" mp[n]"<<mp[n]<<endl;
        return mp[n];
    }
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i*i==n) mp[n]=1+cd(i);
                else
                mp[n]=1+cd(i)+cd(n/i);
//                cout<<"n="<<n<<" mp[n]= "<<mp[n]<<"i= "<<i<<endl;
                return mp[n];
            }
        }

        mp[n]=1;
//        cout<<"n="<<n<<" mp[n]"<<mp[n]<<endl;
        return mp[n];
    }
}

void seive()
{
    ar[1]=1;
    for(int i=2;i*i<=1000;i++)
    {
        if(ar[i]==0)
        {
            v.push_back(i);
            for(int j=i+i;j<=1000;j=j+i)
            {
                ar[j]=1;
            }
        }
    }

}

int main()
{
//    seive();
//    cout<<cd(100000)+1;
    int t, a, b, g;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &b);
        g=__gcd(a,b);
        int n=nOfD(g);
        mp[g]=n;
//        cout<<mp[g]<<endl;
        printf("%d\n", mp[g]);
    }

    return 0;
}
