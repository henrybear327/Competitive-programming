#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    string input;
    getline(cin, input);

    string item;
    stringstream ss;
    ss.str(input);
    vector<int> nums;
    while (getline(ss, item, ' ')) {
        nums.push_back(stoi(item));
    }

    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) {
        int left = 0, right = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                left += nums[j];
            } else
                right += nums[j];
        }

        if (left == right) {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
}

int main()
{
    string inp;
    getline(cin, inp);
    int ncase = stoi(inp);
    while (ncase--) {
        solve();
    }

    return 0;
}
