// WA
// pq won't satisfy the condition "smallest x first"

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

int main()
{
    int n;
    scanf("%d", &n);

    // record number cnt and position
    unordered_map<ll, set<int>> nums;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        nums[num].insert(i);
    }

    // push to pq
    priority_queue<ii> pq;
    for (auto i : nums) {
        pq.push(ii(i.second.size(), i.first)); // cnt, who
    }

    // merge till top is one
    while (pq.top().first > 1) {
        ll num = pq.top().second;
        ll cnt = pq.top().first;
        pq.pop();

        if ((int)nums[num].size() != cnt) // outdated
            continue;

        // get set begin
        auto it = nums[num].begin();
        // remove first two indices
        it = nums[num].erase(it);
        ll idx = *it; // get right index
        it = nums[num].erase(it);

        if (it == nums[num].end())
            nums.erase(num);
        else
            pq.push(ii(nums[num].size(), num));

        nums[num * 2].insert(idx);
        pq.push(ii(nums[num * 2].size(), num * 2));
    }

    // output ans
    vector<ii> ans;
    for (auto i : nums) {
        // printf("%d %d\n", i.first, (int)i.second.size());
        // assert((int)i.second.size() == 1);
        if ((int)i.second.size() != 1)
            continue;
        ans.push_back(ii(*i.second.begin(), i.first));
    }
    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());

    for (auto i : ans)
        printf("%lld ", i.second);

    return 0;
}
