#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[100], dp[100];

int main() {
    int n, max_, k, ans[100], maxLisLength, index;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    maxLisLength = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        if(dp[i] > maxLisLength) {
            maxLisLength = dp[i];
            index = i;
        }
    }

    k = 0;
    max_ = 1000000000;
    while(index > 0) {
        if(arr[index] < max_ && dp[index] == maxLisLength) {
            ans[k++] = arr[index];
            max_ = arr[index];
            maxLisLength -= 1;
        }
        --index;
    }

    for(k = k - 1; k >= 0; --k)
        printf("%d ", ans[k]);
    printf("\n");

    return 0;
}
/*
6
1 4 10 3 4 7
4
12 14 16 6
10
1 6 3 7 5 10 7 15 8 3
*/

