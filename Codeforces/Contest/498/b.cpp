#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    ii inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i].second);
        inp[i].first = i;
    }
    sort(inp, inp + n,
    [](const ii &a, const ii &b) {
        return a.second > b.second;
    });

    vector<int> cut;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        cut.push_back(inp[i].first);
        sum += inp[i].second;
    }
    cut.push_back(n);

    sort(cut.begin(), cut.end());
    cut[0] = 0;
    printf("%d\n", sum);
    for (int i = 1; i < (int)cut.size(); i++) {
        printf("%d ", cut[i] - cut[i - 1]);
    }

    return 0;
}
