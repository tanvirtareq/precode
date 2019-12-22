#include<bits/stdc++.h>

#define inp(a) cin>>a.x>>a.y
#define out(a) cout<<a.x<<a.y<<endl

using namespace std;

typedef long long int li;

#define isEqual(a, b) ((a.x==b.x and a.y==b.y)?1:0)
#define distsq(a, b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct point{
li x, y;
};

li orientation(point a, point b, point c)
{
    li f=(a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);

    if(f==0) return 0;

    if(f<0) return 2;

    return 1;

}

bool isMdl(point a, point b, point m)
{
    if(m.x<=max(a.x, b.x) and m.x>=min(a.x, b.x) and m.y<=max(a.y, b.y) and m.y>=min(a.y, b.y)) return 1;

    else return 0;

}

bool isIntersect(point a1, point a2, point b1, point b2)
{



    if(isEqual(a1, a2) and isEqual(b1, b2 ))
    {
        if(isEqual(a1, b1))
        {
            return 1;
        }

        return 0;
    }

    if(isEqual(a1, a2))
    {
        if(isMdl(b1, b2, a1)) return 1;
        return 0;
    }

    if(isEqual(b1, b2))
    {
        if(isMdl(a1, a2, b1)) return 1;
        return 0;
    }

    if(isEqual(a1, b1)) return 1;
    if(isEqual(a1, b2)) return 1;
    if(isEqual(a2, b2)) return 1;
    if(isEqual(a2, b1)) return 1;

    li Oa1a2b1=orientation(a1, a2, b1);
    li Oa1a2b2=orientation(a1, a2, b2);
    li Ob1b2a2=orientation(b1, b2, a2);
    li Ob1b2a1=orientation(b1, b2, a1);

    if(Oa1a2b1==0 and Oa1a2b2==0 and Ob1b2a1==0 and Ob1b2a2==0)
    {
        if(isMdl(a1, a2, b1) or isMdl(a1, a2, b2)) return 1;
        if(isMdl(b1, b2 , a1) or isMdl(b1, b2 , a2)) return 1;

        return 0;

    }

    if(Oa1a2b1!=Oa1a2b2 and Ob1b2a2!=Ob1b2a1)
        return 1;

    return 0;

}

void swap(point *a, point *b)
{
    point temp;

    temp.x=a->x;
    temp.y=a->y;

    a->x=b->x;
    a->y=b->y;

    b->x=temp.x;
    b->y=temp.y;

    return;
}

point ar[10010];

bool cmp(point a, point b)
{
    if(orientation(ar[0], a, b)==1) return true;

    if(orientation(ar[0], a, b)==0 and distsq(ar[0], a)>distsq(ar[0], b)) return true;

    else return false;

}

    stack<point> st;
point nextToTop()
{
    point ret=st.top();
    st.pop();
    point r=st.top();

    st.push(ret);

    return r;

}



int main()
{

    int t;
    cin>>t;



    inp(ar[0]);

    int mn=0;

    for(int i=1;i<t;i++)
    {
        inp(ar[i]);

        if(ar[i].y<ar[mn].y)
        {
            mn=i;
        }

        else if(ar[i].y==ar[mn].y and ar[i].x<ar[mn].x)
            mn=i;
    }

    point temp=ar[mn];
    ar[mn]=ar[0];
    ar[0]=temp;


//    out(ar[0]);

    sort(ar+1, ar+t, cmp);

    int m=1;

    for(int i=2;i<t;)
    {
//        out(ar[0])

//        cout<<orientation(ar[0], ar[i], ar[m])<<endl;

        while(orientation(ar[0], ar[i], ar[m])==0)
        {
            i++;
//            cout<<i<<endl;
        }

//        cout<<i<<endl;
        ar[++m]=ar[i];
        i++;
    }

//    cout<<"yesy"<<endl;


    st.push(ar[0]);
    st.push(ar[1]);

    for(int i=2;i<=m;i++)
    {
        while(orientation(nextToTop(), st.top(), ar[i])==2)
        {
            st.pop();
        }
        st.push(ar[i]);
    }

    point x=st.top();
    point y=x;

    st.pop();

    double ans=0;

    while(!st.empty())
    {
        ans+=sqrt(distsq(x, st.top()));

        x=st.top();

        st.pop();
    }
    ans+=sqrt(distsq(x,y));

    cout<<fixed<<setprecision(1)<<ans<<endl;

	return 0;
}

