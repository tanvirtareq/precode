#include<bits/stdc++.h>

using namespace std;

void x()
{
        int ar[]={1, 4, 2, 6, 8, 4, 6, 3, 6,9, 0, 3, 4, 3, 4, 5,6};

    vector<int>v[101];
    int n=sizeof(ar)/sizeof(int);

    int position=0;
    for(int i=0;i<n;i++)
    {
        int x=ar[i];
        v[x].push_back(i);
    }

    for(int i=0;i<=100;i++)
    {
        cout<<"position of"<<i<<"is"<<endl;
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i].at(j)<<" ";

        }

        cout<<endl;

    }
    return;
}

void int_array_compression_of_mine()
{


     map<int, vector<int> >mp;

     int ar[]={2, -3, 1, -3, -6, -3, 4, -5, 6, 8, 20, 1, -1, -2, 3};

     for(int i=0;i<sizeof(ar)/sizeof(int);i++)
     {
         int x=ar[i];
         mp[x].push_back(i);

     }

     map<int, vector<int> >::iterator it;
     for(it=mp.begin();it!=mp.end();it++)
     {
         int x=it->first;
         cout<<"position of "<<x<<" is"<<endl;
         for(int i=0;i<mp[x].size();i++)
         {
             cout<<mp[x].at(i)<<" ";

         }
         cout<<endl;

     }
    return;
}

void string_array_compression()
{

     map<string, vector<int> >mp;

     string ar[]={"as", "as", "as", "awr", "df", "aw", "awr", "df", "as", "ac"};

     for(int i=0;i<sizeof(ar)/sizeof(string);i++)
     {
         string x=ar[i];
         mp[x].push_back(i);

     }

     map<string, vector<int> >::iterator it;
     for(it=mp.begin();it!=mp.end();it++)
     {
         string x=it->first;
         cout<<"position of "<<x<<" is"<<endl;
         for(int i=0;i<mp[x].size();i++)
         {
             cout<<mp[x].at(i)<<" ";

         }
         cout<<endl;

     }


    return;
}

int main()
{
    string_array_compression();
    return 0;
}
