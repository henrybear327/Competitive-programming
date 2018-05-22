#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int ma[4][4], mb[4][4];

int seq[4][4];
ii score[4][4];
ii lastScoreMat[4][4];

ll k;

ii ans;

bool aWin(int a, int b)
{
    // 3, 2
    // 2, 1
    // 1, 3
    if (a - b == 1 || (a == 1 && b == 3))
        return 1;
    return 0;
}

bool bWin(int a, int b)
{
    // 2, 3
    // 1, 2
    // 3, 1
    if (b - a == 1 || (a == 3 && b == 1))
        return 1;
    return 0;
}

void dfs(int a, int b, int step, ii lastScore)
{
    if (step == k) {
        ans = lastScore;
        return;
    }

    // printf("a = %d b = %d\n", a, b);
    if (seq[a][b] != -1) {
        ii diff = ii(lastScore.first - lastScoreMat[a][b].first,
                     lastScore.second - lastScoreMat[a][b].second);

        // seq[a][b] was the last visit
        ans = lastScoreMat[a][b];
        // printf("%lld %lld\n", ans.first, ans.second);

        k -= seq[a][b];
        // printf("k = %lld\n", k);

        int length = step - seq[a][b];
        ll iterations = k / length;

        ans.first += iterations * diff.first;
        ans.second += iterations * diff.second;
        // printf("%lld %lld\n", ans.first, ans.second);

        ll remainder = k % length;
        // printf("r = %lld\n", remainder);

        int nextA = a;
        int nextB = b;
        for (int i = 0; i < remainder; i++) {
            // printf("na = %d nb = %d\n", nextA, nextB);
            ans.first += aWin(nextA, nextB);
            ans.second += bWin(nextA, nextB);
            // printf("%lld %lld\n", ans.first, ans.second);

            int tmp = nextA; // WOW such an error
            nextA = ma[nextA][nextB];
            nextB = mb[tmp][nextB]; // you need original A, not modified A!
        }

        return;
    }

    seq[a][b] = step;
    lastScoreMat[a][b] = lastScore;
    score[a][b] = ii(lastScore.first + aWin(a, b), lastScore.second + bWin(a, b));
    dfs(ma[a][b], mb[a][b], step + 1, score[a][b]);
}

int main()
{
    ll a, b;
    scanf("%lld %lld %lld", &k, &a, &b);

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            scanf("%d", &ma[i][j]);

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            scanf("%d", &mb[i][j]);

    memset(seq, -1, sizeof(seq));

    dfs(a, b, 0, ii(0, 0));

    printf("%lld %lld\n", ans.first, ans.second);

    return 0;
}