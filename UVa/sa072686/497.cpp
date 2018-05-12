#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

string inp;

void solve()
{
    vector<int> nums;
    while (getline(cin, inp) && inp != "") {
        // cout << inp << endl;
        nums.push_back(stoi(inp));
    }

    if (nums.size() == 0) {
        cout << "Max hits: " << 0 << endl;
        return;
    }

    // lis
    int n = nums.size();
    vector<ii> lis(n, ii(INT_MAX, -1));
    vector<int> path(n, -1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), ii(nums[i], -1));
        *it = ii(nums[i], i);
        if (it != lis.begin())
            path[i] = next(it, -1)->second;
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i].first != INT_MAX)
            len = i;
        else
            break;
    }

    len++;
    cout << "Max hits: " << len << endl;
    vector<int> seq;
    int who = lis[len - 1].second;
    while (who != -1) {
        seq.push_back(nums[who]);
        who = path[who];
    }
    reverse(seq.begin(), seq.end());

    for (int i = 0; i < len; i++) {
        // cout << "index " << i << " " << len << endl;
        cout << seq[i] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getline(cin, inp);
    int ncase = stoi(inp);
    getline(cin, inp);
    while (ncase--) {
        solve();

        if (ncase)
            cout << endl;
    }
    return 0;
}
