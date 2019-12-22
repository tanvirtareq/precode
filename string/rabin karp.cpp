#include<bits/stdc++.h>

using namespace std;

typedef long long li;

int d=256, q=11;

li inline bigmod(li base, li power, li mod)
{

    if(power==0) return 1;

    if(power==1) return base%mod;

    li x=bigmod(base, power/2, mod);

    if(power&1)
    {
        return (base*x*x)%mod;
    }

    else return (x*x)%mod;

}

int find_h(string pattern)
{
    int h=1;

    for(int i=1;i<pattern.size();i++)
        h=(h*d)%q;

    return h;

}

pair<int, int>  findHashValueOfPattern(string pattern, string text, int h)
{
    int pathashval=0, textHashVal;

    for(int i=0;i<pattern.size();i++)
    {
        pathashval=(pathashval*d+pattern[i])%q;
        textHashVal=(textHashVal*d+text[i])%q;

    }

    cout<<pathashval<<" "<<textHashVal<<endl;

    return make_pair(pathashval, textHashVal);

}

void check(string text, string pattern, int i)
{
    int s=i;
    cout<<s<<endl;

    for(int j=0;j<pattern.size();j++, i++)
    {
        if(pattern[j]!=text[i])
        {
            return;
        }

    }

    cout<<" match at index "<<s<<endl;

}

void  Search(string text,string pattern,int textHashVal,int patHashval, int h)
{
    cout<<h<<endl;
    for(int i=0;i<text.size();i++)
    {

        cout<<" text "<<textHashVal<<endl;
        int lastIndxOfText=i+pattern.size()-1;

        for(int k=i;k<=lastIndxOfText;k++)
            cout<<text[k];

        cout<<endl;

        if(textHashVal==patHashval)
            check(text, pattern, i);

        if(lastIndxOfText>=text.size()) break;

        textHashVal=((textHashVal-text[i]*h)*d+text[lastIndxOfText+1])%q;
        if(textHashVal<0) textHashVal+=q;


    }

}

int main()
{

    string text, pattern;

    while(cin>>text>>pattern)
    {
        int h=find_h(pattern);

        pair<int, int> p=findHashValueOfPattern(pattern, text, h);

        int patHashval=p.first;

        int textHashVal=p.second;

        Search(text, pattern, textHashVal, patHashval, h);
    }

    return 0;
}
