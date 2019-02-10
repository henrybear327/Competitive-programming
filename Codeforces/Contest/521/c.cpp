#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    unordered_map<ll, int> cnt;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        sum += inp[i];
        cnt[inp[i]]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        sum -= inp[i];
        cnt[inp[i]]--;

        if (sum % 2 == 0) {
            if (cnt.find(sum / 2) != cnt.end() && cnt[sum / 2] > 0)
                ans.push_back(i + 1);
        }

        sum += inp[i];
        cnt[inp[i]]++;
    }

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d ", i);

    return 0;
}
