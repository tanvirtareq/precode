#include <bits/stdc++.h>
#define llu long long int
using namespace std;

struct Point {

    llu x, y;

    bool operator<(Point p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

llu cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> A)
{
    int n = A.size(), k = 0;
    if (n <= 3)
        return A;

    vector<Point> ans(2 * n);

    sort(A.begin(), A.end());


    for (int i = 0; i < n; ++i) {

        while (k >= 2 && cross_product(ans[k - 2],
                          ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }

    for (size_t i = n - 1, t = k + 1; i > 0; --i) {

        while (k >= t && cross_product(ans[k - 2],
                           ans[k - 1], A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }

    ans.resize(k - 1);

    return ans;
}

int main()
{

    return 0;
}
