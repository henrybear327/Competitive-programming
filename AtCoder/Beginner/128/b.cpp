#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int n;
    scanf("%d", &n);

    iii inp[n];
    for (int i = 0; i < n; i++) {
        char s[111];
        scanf("%s %d", s, &inp[i].second.second);
        inp[i].first = i + 1;
        inp[i].second.first = s;
    }

    sort(inp, inp + n, [](const iii a, const iii b) -> bool {
        if (a.second.first == b.second.first)
            return a.second.second > b.second.second;
        return a.second.first < b.second.first;
    });

    for (int i = 0; i < n; i++)
        printf("%d\n", inp[i].first);

    return 0;
}
