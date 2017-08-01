#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

void solve(int n)
{
    map<int, int> m;
    vector<int> seq;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);

        m[cur]++;

        if (mx < m[cur])
            mx = m[cur];

        seq.push_back(cur);
    }
	
	printf("%d\n", mx);
    sort(seq.begin(), seq.end());
    for (int i = 0; i < mx; i++) {
        for (int j = i; j < n; j += mx)
            printf("%d%c", seq[j], j + mx < n ? ' ' : '\n');
    }
}

int main()
{
    int n;
    bool first = true;
    while (scanf("%d", &n) == 1 && n) {
        if (first)
            first = !first;
        else
            printf("\n");
        solve(n);
    }

    return 0;
}
