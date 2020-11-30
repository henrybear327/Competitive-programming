#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int dist[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    int sequence[n - 1];
    for(int i = 0; i < n - 1; i++)
        sequence[i] = i + 1;

    int ans = 0;
    do {
        ll acc = 0;

        int prev = 0;
        for(int i = 0; i < n - 1; i++) {
            acc += (ll)dist[prev][sequence[i]];
            prev = sequence[i];
        }
        acc += (ll)dist[prev][0];

        if(acc == k)
            ans++;
    } while(next_permutation(sequence, sequence + n - 1));

    printf("%d\n", ans);

    return 0;
}
