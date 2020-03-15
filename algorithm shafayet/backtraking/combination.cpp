#include<bits/stdc++.h>

using namespace std;

int n, r;
char ch[10], c[10];
bool a[10];


void print()
{
    for(int i=1;i<=r;i++)
        printf("%c", c[i]);
    cout<<endl;
    return;
}


void combination(int idx, int prepo)
{
    if(idx>r)
    {
        print();
        return;
    }
    for(int i=prepo;i<=n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            c[idx]=ch[i];
            combination(idx+1, i);
            a[i]=0;
        }
    }
    return;
}

int main()
{
    cin>>n>>r;

    char tmp='a';
    for(int i=1;i<=n;i++)
    {
       ch[i]=tmp;
       tmp++;
    }
    int idx=1;
    combination(idx, 1);

    return 0;
}
