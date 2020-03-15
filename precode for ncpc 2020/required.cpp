#include<bits/stdc++.h>
using namespace std;
/// Geometry
/// Convex hull:
struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
Chinese remainder theorem:
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
Modular multiplicative inverse:
/**
modular multiplicative inverse from 1 to N in o(n) complexity
*/
void modularMultiplicativeInverse()
{
    int inv[SIZE];
    inv[1] = 1;
    for ( int i = 2; i <= n; i++ )
    {
        inv[i] = (-(m/i) * inv[m%i] ) % m;
        inv[i] = inv[i] + m;
    }
}

Phi:
/// from 1 to n ,the number of integer that's gcd(n,x)=1 is the totien of n
/**
n=p1^(a1)*p2^(a2)*...pk^(ak)
then phi(n)=n*(p1-1)/p1*(p2-1)/p2*...(pk-1)/pk

*/

#include<bits/stdc++.h>

using namespace std;

ll totient(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}



/// this function will pre calculate phi of 1 to n in O(n) complexity
int lp[MX + 10];
int phi[MX + 10];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= MX; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MX; ++j)
            lp[i * pr[j]] = pr[j];
    }
}



/// rhis will pre calculate phi of 1 to n in O(nlogn) complexity
ll p[MX+10], g[MX+10];

void precalphi()
{
    for(int i=1;i<=MX;i++) p[i]=i;

    for(ll i=2;i<=MX;i++)
    {
        if(p[i]==i)
        {
            for(ll j=i;j<=MX;j+=i)
            {
                p[j]=p[j]/i*(i-1);
            }
        }
    }
}


/// this will precalculate all pair gcdsum for 1 to n in O(nlogn) complexity
void gcdx()
{
    for(ll i=2;i<=MX;i++) g[i]=phi[i];

    for(ll i=2;i<=MX;i++)
    {

            for(ll j=i+i;j<=MX;j+=i)
            {
                g[j]+=j*phi[i]/i;
            }
    }

    for(ll i=2;i<=MX;i++) g[i]+=g[i-1];
}


int main()
{
    int x=totient(120);
    cout<<x<<endl;

    return 0;
}

Heckenbush:
vector<int> adj[1000];
int hackenbush(int u, int parent)
{
    int result = 0;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == parent)
            continue;
        result ^= hackenbush (v, u) + 1;
    };
    return result;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int rs=hackenbush(1, 0);
    if(rs)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;

}

Linear diaphantine equation:
pair<int, int>  find_one_solution_of_linear_diophantine_equation(int a, int b, int c)
{
    pair<int, int> p, q;

    int g=__gcd(abs(a) , abs(b));

    if(c%g!=0)
    {
        cout<<"no solution"<<endl;
        return p;
    }

    q=extendedEuclideanCover(a,b);

    p.first=q.first*c/g;
    p.second=q.second*c/g;

    return p;

}
Geo template:

const double INF = 1e100;
const double EPS = 1e-9;

int EQ(double x)
{
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c) const
    {
        return PT(x*c, y*c);
    }
    PT operator / (double c) const
    {
        return PT(x/c, y/c);
    }
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double dist2D_sqr(PT p, PT q)
{
    return dot(p-q, p-q);
}
double dist2D(PT p, PT q)
{
    return sqrt(dot(p-q, p-q));
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

/// Rotates a point CCW or CW around the Origin

PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}

PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}

PT RotateCCW(PT p, double theta)
{
    return PT(p.x*cos(theta)-p.y*sin(theta), p.x*sin(theta)+p.y*cos(theta));
}
PT RotateCW(PT p, double theta)
{
    return PT(p.x*cos(theta)+p.y*sin(theta), -p.x*sin(theta)+p.y*cos(theta));
}

/// Finds a point from 'a' through 'b' with distance 'd'

PT PointAlongLine(PT a, PT b, double d)
{
    return a+(((b-a)/sqrt(dot(b-a,b-a)))*d);
}

/// Projects the point 'c' onto line through 'a' and 'b' (assuming a != b)

PT ProjectPointToLine(PT a, PT b, PT c)
{
    return a+(b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

/// Projects point 'c' onto the line segment through 'a' and 'b'

PT ProjectPointToSegment(PT a, PT b, PT c)
{
    double r=dot(b-a,b-a);

    if(fabs(r)<EPS) return a;

    r=dot(c-a, b-a)/r;

    if(r<0) return a;
    if(r>1) return b;

    return a+(b-a)*r;
}

/// Computes distance from 'c' to the line segment between 'a' and 'b'

double DistanceFromPointToSegment(PT a, PT b, PT c)
{
    return dist2D(c, ProjectPointToSegment(a, b, c));
}

/// Computes minimum distance from a point 'p' to a line 'AB'

double DistToLine(PT p, PT A, PT B)
{
    double scale=dot(p-A,B-A)/dot(B-A,B-A);

    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);

    return dist2D(p, c);
}

/// Computes minimum distance from a point 'p' to a line segment 'AB'

double DistToLineSegment(PT p, PT A, PT B)
{
    PT c;
    if(dot(B-A,p-A)<EPS) return dist2D(p, A);
    if(dot(A-B,p-B)<EPS) return dist2D(p, B);

    return DistToLine(p, A, B);
}

/// Checks whether a point 'p' is on the line segment between 'a' and 'b' or not

bool PointOnSegment(PT p, PT a, PT b)
{
    if(fabs(cross(p-b,a-b))<EPS)
    {
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }

    return false;
}

/// Determines whether the lines from 'a' to 'b' and 'c' to 'd' are parallel or not

bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d))<EPS;
}

/// Determines if the lines from 'a' to 'b' and 'c' to 'd' are collinear or not

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c))<EPS && fabs(cross(c-d, c-a))<EPS;
}

/// Before calling this, check whether the line segments are parallel or not
/// Determines whether the line segment between 'a' and 'b' intersects with the line segment between 'c' and 'd'

bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if(LinesCollinear(a, b, c, d))
    {
        if(dist2D_sqr(a, c)<EPS || dist2D_sqr(a, d)<EPS || dist2D_sqr(b, c)<EPS || dist2D_sqr(b, d)<EPS) return true;
        if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0) return false;
        return true;
    }

    if(cross(d-a, b-a)*cross(c-a, b-a)>0) return false;
    if(cross(a-c, d-c)*cross(b-c, d-c)>0) return false;

    return true;
}

/// Computes intersection of the line passing through 'a' and 'b' with the line passing through 'c' and 'd'

PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    double a1=a.y-b.y;
    double b1=b.x-a.x;
    double c1=cross(a, b);
    double a2=c.y-d.y;
    double b2=d.x-c.x;
    double c2=cross(c, d);
    double D=a1*b2-a2*b1;

    return PT((b1*c2-b2*c1)/D, (c1*a2-c2*a1)/D);
}

/// Computes center of the circle passing through the points 'a', 'b' and 'c'

PT ComputeCircleCenter(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

/// Determines whether a point 'q' is on the boundary of the polygon 'p' or not

bool PointOnBoundaryOfPolygon(const vector<PT>p, PT q)
{
    int s=p.size();
    for(int i=0, j=s-1; i<s; j=i++)
    {
        if(PointOnSegment(q, p[j], p[i])) return true;
    }

    return false;
}


/// Determines whether a point 'q' is in a possibly non-convex polygon or not.
/// Returns '1' for strictly interior points, '0' for strictly exterior points, and '0' or '1' for the remaining points.

bool PointInPolygon(const vector<PT>p, PT q)
{
    bool c=0;
    int s=p.size();

    for(int i=0,j=s-1; i<s; j=i++)
    {
        if(((p[i].y>q.y)!=(p[j].y>q.y))&&(q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))) c=!c;
    }

    return c;
}

/// Computes intersection of the line through points 'a' and 'b' with the circle centered at 'c' with radius 'r'

vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT>ret;
    b=b-a;
    a=a-c;

    double A=dot(b, b);
    double B=dot(a, b);
    double C=dot(a, a)-r*r;
    double D=B*B-A*C;

    if(D<-EPS) return ret;

    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);

    if(D>EPS) ret.push_back(c+a+b*(-B-sqrt(D))/A);

    return ret;
}

/// Computes intersection of the circle centered at 'c1' with radius 'r1' with the circle centered at 'c2' with radius 'r2'

vector<PT> CircleCircleIntersection(PT c1, PT c2, double r1, double r2)
{
    vector<PT>ret;

    double d=dist2D(c1, c2);
    if(d>r1+r2 || d+min(r1, r2)<max(r1, r2)) return ret;

    double x=(d*d-r2*r2+r1*r1)/(2.0*d);
    double y=sqrt(r1*r1-x*x);

    PT v=(c2-c1)/d;

    ret.push_back(c1+v*x+RotateCCW90(v)*y);
    if(y>0) ret.push_back(c1+v*x-RotateCCW90(v)*y);

    return ret;
}

/// Computes the area of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion

double ComputeSignedArea(const vector<PT>p)
{
    double area=0.0;
    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }

    return area/2.0;
}

double ComputeArea(const vector<PT>p)
{
    return fabs(ComputeSignedArea(p));
}

/// Computes the centroid of a possibly non-convex polygon, assuming that the coordinates are listed in a clockwise or counterclockwise fashion

PT ComputeCentroid(const vector<PT>p)
{
    PT c=PT(0.0,0.0);
    double scale=6.0*ComputeSignedArea(p);

    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%p.size();
        c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }

    return c/scale;
}

/// Checks whether or not a the polygon 'p' (in CW or CCW order) is simple

bool IsSimple(const vector<PT>p)
{
    for(int i=0; i<p.size(); i++)
    {
        for(int k=i+1; k<p.size(); k++)
        {
            int j=(i+1)%p.size();
            int l=(k+1)%p.size();

            if(i==l || j==k) continue;

            if(SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
        }
    }

    return true;
}


/// Returns a parallel line of the line 'ab' in CCW direction with d distance from 'ab'

pair<PT,PT> GetParallelLine(PT a, PT b, double d)
{
    return make_pair(PointAlongLine(a, RotateCCW90(b-a)+a, d), PointAlongLine(b, RotateCW90(a-b)+b, d));
}

/// Returns the perpendicular line of the line 'ab' which intersects with it at point 'c' in CCW direction

pair<PT,PT> GetPerpendicularLine(PT a, PT b, PT c)
{
    return make_pair(RotateCCW90(a-c)+c,RotateCCW90(b-c)+c);
}

vector<PT>HalfPlaneIntersection(vector<PT>poly, pair<PT,PT>ln)
{
    vector<PT>ret;
    int s=poly.size();
    for(int i=0; i<s; i++)
    {
        double c1=cross(ln.second-ln.first, poly[i]-ln.first);
        double c2=cross(ln.second-ln.first, poly[(i+1)%s]-ln.first);

        if(EQ(c1)>=0) ret.push_back(poly[i]);
        if(EQ(c1*c2)<0)
        {
            if(!LinesParallel(poly[i], poly[(i+1)%s], ln.first, ln.second))
            {
                ret.push_back(ComputeLineIntersection(poly[i], poly[(i+1)%s], ln.first, ln.second));
            }
        }
    }

    return ret;
}


/// Computes distance between a point (x,y,z) and a plane ax+by+cz=d

double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

/// this part sort points in clockwise

vector<pair<PT, int> > v;

bool helper(const PT &p)
{
    return cross(v[0].first, p)>0 || (cross(v[0].first, p)==0 && dot(v[0].first, p)>0);
}

int compareClockWise(pair<PT, int> a, pair<PT, int> b)
{
    return helper(a.first)==helper(b.first) && cross(a.first, b.first)>0 ||
        (helper(a.first)&& !helper(b.first));
}





