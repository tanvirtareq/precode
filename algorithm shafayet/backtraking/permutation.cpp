#include<bits/stdc++.h>

using namespace std;
int n=4, r=3;

bool a[10];

int p[10];

char ch[10];


void print()
{
    for(int i=1;i<=r;i++)
        printf("%c", p[i]);
    cout<<endl;
    return;
}

void set_position(int idx)
{
    if(idx>r)
    {
        print();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            p[idx]=ch[i];
            set_position(idx+1);
            a[i]=0;
        }
    }
}

void permutation()
{
    int idx=1;
    set_position(idx);

    return;
}


int main()
{
    ch[1]='a';
    ch[2]='b';
    ch[3]='c';
    ch[4]='d';
    permutation();

    return 0;
}
