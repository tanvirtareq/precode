#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int chains[1000], dp[1000][1000];

void printAnswer(int start, int end)
{
    if(end - start == 1) {
        printf("M%d", end);
        return ;
    }

    int min_ = inf, index, left, right;

    for(int i = start + 1; i < end; ++i)
    {
        left = dp[start][i];
        right = dp[i][end];
        if(min_ > left + (chains[start] * chains[i] * chains[end]) + right)
        {
            min_ = left + chains[start] * chains[i] * chains[end] + right;
            index = i;
        }
    }

    if(index - start == 1) {
        printAnswer(start, index);
    }
    else
    {
        printf("(");
        printAnswer(start, index);
        printf(")");
    }

    if(end - index == 1) {
        printAnswer(index, end);
    }
    else
    {
        printf("(");
        printAnswer(index, end);
        printf(")");
    }
    return ;
}

int main()
{

    int t, n;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d", &chains[i]);

        for(int i = 1; i < n; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {

                if(i - j == 1)
                    dp[j][i] = 0;
                else
                {
                    dp[j][i] = inf;
                    for(int k = j; k <= i; ++k)
                        dp[j][i] = min(dp[j][i], dp[j][k] +
                                       chains[j] * chains[k] * chains[i] + dp[k][i]);
                }
            }
        }

        printf("Answer : %d\n", dp[0][n - 1]);
        printAnswer(0, n - 1);
        printf("\n");
    }
    return 0;
}

/*
4
5
40 20 30 10 30
Answer : 26000
(M1(M2M3))M4



5
10 20 30 40 30
5
50 30 30 20 30
3
10 20 30
*/
