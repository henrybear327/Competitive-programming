#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
    int idx, val, col;
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Data inp[n];
    int cnt[5555] = {0};
    for (int i = 0; i < n; i++) {
        inp[i].idx = i;
        scanf("%d", &inp[i].val);

        cnt[inp[i].val]++;
        if (cnt[inp[i].val] > k) {
            printf("NO\n");
            return 0;
        }
    }

    sort(inp, inp + n,
    [](const Data &a, const Data &b) {
        return a.val < b.val;
    });

    for (int i = 0; i < n; i++)
        inp[i].col = (i % k) + 1;

    sort(inp, inp + n,
    [](const Data &a, const Data &b) {
        return a.idx < b.idx;
    });

    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d ", inp[i].col);

    return 0;
}
