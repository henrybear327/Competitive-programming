#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_N = 12;
const int MAX_M = 12;
const ll MOD = 100000000;

int N, M;
// bool is_fertile[MAX_N][MAX_M];
int inf[MAX_N]; // infertile squares mask
ll dp[MAX_N][1 << MAX_M];

// dp[r][S] = 上方 r + 1 行，第 r 行選的田地的集合為 S，的方法數
// 考慮上一行選的田地集合 P
// dp[r][S] = sum([
//     dp[r - 1][P]
//     for all P is not adjacent to S and P is valid
// ])

// base: dp[0][S] = 1 if S is valid else 0
// ans: sum(dp[N - 1][S] for all valid S)

inline bool is_valid(int r, int S) {
    // for (int i = 0; i < M; i++) {
    //     // adj in current row
    //     if (i >= 1 && (S & (1 << i)) && (S & (1 << (i - 1)))) {
    //         return false;
    //     }
    //     // use infertile squares
    //     if ((S & (1 << i)) && !is_fertile[r][i]) {
    //         return false;
    //     }
    // }
    // return true;
    if (S & (S << 1))
        return false;
    if (S & inf[r])
        return false;
    return true;
}

inline bool is_adj(int P, int S) {
    // for (int i = 0; i < M; i++) {
    //     // if there's adjacent at column i
    //     if ((S & (1 << i)) && (P & (1 << i))) {
    //         return true;
    //     }
    // }
    // return false;
    return (P & S) != 0;
}

ll solve() {
    // base
    for (int S = 0; S < (1 << M); S++) {
        if (is_valid(0, S)) {
            dp[0][S] = 1;
        }
    }

    // dp
    for (int r = 1; r < N; r++) {
        for (int S = 0; S < (1 << M); S++) {
            dp[r][S] = 0;

            if (!is_valid(r, S)) {
                continue;
            }

            for (int P = 0; P < (1 << M); P++) {
                if (is_valid(r - 1, P) && !is_adj(P, S)) {
                    dp[r][S] = (dp[r][S] + dp[r - 1][P]) % MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < (1 << M); i++) {
        ans += dp[N - 1][i];
        ans %= MOD;
    }

    return ans;
}

int main() {
    while (scanf("%d %d", &N, &M) != EOF) {
        memset(inf, 0, sizeof(inf));
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int inp; scanf("%d", &inp);
                // is_fertile[i][j] = (inp == 1);
                if (inp == 0) {
                    inf[i] = (inf[i] | (1 << j));
                }
            }
        }

        printf("%lld\n", solve());
    }

    return 0;
}
