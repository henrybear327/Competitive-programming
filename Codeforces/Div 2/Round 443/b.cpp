#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    ll k;
    scanf("%d %lld", &n, &k);

    vector<int> inp;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        inp.push_back(num);
    }

    if (k >= n - 1) {
        // the one with max val from the start of line (n)
        printf("%d\n", n);
    } else {
        int cnt = 0;
        int head = 0;
        int rival = 1;
        while (cnt != k) {
            if (inp[head] > inp[rival]) {
                inp.push_back(inp[rival]);
                rival++;
                cnt++;
            } else {
                // lose
                inp.push_back(inp[head]);
                rival++;
                head = rival - 1;
                cnt = 0;
            }
        }
        printf("%d\n", inp[head]);
    }

    return 0;
}
