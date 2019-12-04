#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1000001;
bool dp[N];

int main()
{
    memset(dp, 0, sizeof(N));
    dp[0] = true;

    for (int i = 100; i <= 105; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[j] && j + i < N)
                dp[j + i] = true;
        }
    }

    int x;
    scanf("%d", &x);
    printf("%d\n", dp[x]);

    return 0;
}
