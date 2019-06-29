#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // operation A and B: greedy, enumerate no touch zone
    // operation C and D: if started, means no operation A and B anymore

    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int mx = 0;
    // no touch zone size
    for (int i = max(0, n - k); i < n; i++) {
        // enumerate the left bound
        for (int l = 0; l < n && l + i <= n; l++) {
            vector<int> in;
            int sum = 0;
            for (int x = 0; x < n; x++) {
                if (l <= x && x < l + i)
                    continue;
                in.push_back(inp[x]);
                sum += inp[x];
            }

            sort(in.begin(), in.end());

            int rem = k - (n - i);
            for (int x = 0; x < rem && x < (int)in.size(); x++) {
                if (in[x] < 0)
                    sum -= in[x];
                else
                    break;
            }

            // printf("%d %d %d\n", l, i, sum);
            mx = max(mx, sum);
        }
    }

    printf("%d\n", mx);

    return 0;
}
