#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, ll> ii;

int main()
{
    int n;
    scanf("%d", &n);

    // record number cnt and position
    map<ll, set<int>> nums;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        nums[num].insert(i);
    }
    
    // FUCK the reference
    for (auto &i : nums) { // start merging from the small number
        while (i.second.size() > 1) {
            auto it = i.second.begin();
            int left = *it;
            int right = *(next(it));

            it = i.second.erase(it);
            it = i.second.erase(it);
            
            nums[i.first * 2].insert(right);
        }
    }

    vector<ii> ans;
    for (auto i : nums) {
        if ((int)i.second.size() > 0) {
            ans.push_back(ii(*i.second.begin(), i.first));
        }
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%lld ", i.second);

    return 0;
}
