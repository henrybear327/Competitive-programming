#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// linear time solution
// Count the number of elements in an unsorted array which are smaller than the
// given element.
void solve()
{
    int n;
    scanf("%d", &n);

    vector<ii> inp;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        inp.push_back(ii(tmp, i));
    }
    sort(inp.begin(), inp.end());

    int k;
    scanf("%d", &k);
    k--;

    for (int i = 0; i < n; i++)
        if (inp[i].second == k)
            printf("%d\n", i + 1);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
