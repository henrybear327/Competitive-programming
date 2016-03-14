#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    const int k_orig = k;

    vector<pair<int, int>> devisor;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            int cnt = 0;
            while (k % i == 0) {
                k /= i;
                cnt++;
            }
            devisor.push_back(make_pair(i, 2 * cnt));
            // k --> k ^ 2, all component's exp. will be doubled
        }
    }

    // for prime
    if (k > 1) {
        devisor.push_back(make_pair(k, 2));
    }

    vector<long long int> all_devisor(1, 1);
    // put 1 into the vector first, or it'll be omitted

    // calculate all possible devisor(put in codebook)
    for (int i = 0; i < (int)devisor.size(); i++) {
        int size = (int)all_devisor.size();
        for (int j = 0; j < size; j++) {
            long long int curr = all_devisor[j];
            for (int k = 1; k <= devisor[i].second; k++) {
                all_devisor.push_back(1LL * curr * devisor[i].first);
                curr *= devisor[i].first;
            }
        }
    }

    set<pair<long long int, long long int>> ans;
    for (int i = 0; i < (int)all_devisor.size(); i++) {
        long long int a = (1LL * k_orig * k_orig / all_devisor[i] + k_orig);
        long long int b = k_orig + all_devisor[i];
        ans.insert(make_pair(a, b));
    }

    printf("%d\n", (int)ans.size());
    for (auto i = ans.begin(); i != ans.end(); i++) {
        printf("%lld %lld\n", i->first, i->second);
    }

    return 0;
}
