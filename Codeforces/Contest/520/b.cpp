#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int mxExp = 0;
    int factor = 2;
    vector<ii> factors;
    while (n > 1) {
        int cnt = 0;
        while (n % factor == 0)
            cnt++, n /= factor;
        if (cnt > 0)
            factors.push_back({factor, cnt});
        mxExp = max(mxExp, cnt);
        factor++;
    }

    bool allSame = true;
    for (int i = 1; i < (int)factors.size(); i++) {
        if (factors[i].second != factors[i - 1].second)
            allSame = false;
    }

    // 1 2 3 4 5 6 7 8  9 10
    // 1 2 4 4 8 8 8 8 16 16
    int ans = 0;
    if (mxExp > 1) {
        for (int i = 1;; i++) {
            int lb = 1 << (i - 1);
            int rb = 1 << i;
            if (lb < mxExp && mxExp <= rb) {
                if (mxExp == rb && allSame)
                    ans = i;
                else
                    ans = i + 1;
                break;
            }
        }
    }

    int tot = 1;
    for (auto i : factors)
        tot *= i.first;

    printf("%d %d\n", tot, ans);

    return 0;
}
