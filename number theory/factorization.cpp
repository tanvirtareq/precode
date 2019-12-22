#include<bits/stdc++.h>
#define sz 10000000
using namespace std;

int spf[sz+1];

void find_spf()
{
    spf[1]=1;

    for(int i=2;i*i<=sz;i++)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            for(int j=i*i;j<=sz;j=j+i)
                if(spf[j]==0) spf[j]=i;
        }

    }
    return;

}

map<int, int> factor(int x)
{
    map<int, int> mp;
    while(spf[x]!=1)
    {
        mp[spf[x]]++;
//        cout<<spf[x]<<" ";
        x=x/spf[x];
    }

    return mp;

}

int main()
{
    find_spf();

    map<int , int> mp;
    map<int , int>:: iterator it;

//    for(int i=1;i<=10000;i++)
//        cout<<i<<" "<<spf[i]<<endl;

    mp=factor(10000);
    for(it=mp.begin();it!=mp.end();it++)
        cout<<it->first<<" "<<it->second<<endl;



    return 0;
}
