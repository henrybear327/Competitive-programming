#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector<string> inp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        char tmp[1000];
        scanf("%s", tmp);

        inp.push_back(tmp);
        mx = max(mx, (int)inp[i].length());
        reverse(inp[i].begin(), inp[i].end());
    }

    int ans = 0;
    bool used[1111] = {false};
    for (int i = mx; i >= 1; i--) {
        unordered_map<string, set<int>> cnt;

        for (int j = 0; j < n; j++) {
            if (used[j])
                continue;
            if ((int)inp[j].length() < i)
                continue;
            cnt[inp[j].substr(0, i)].insert(j);
        }

        set<string> no;
        for (auto j : cnt) {
            if (j.second.size() < 2)
                continue;

            // printf("%s\n", j.first.c_str());
            string di = j.first;
            if (no.find(di) != no.end())
                break;
            // cout << di << endl;
            no.insert(di);
            ans += 2;
            int cand1 = *j.second.begin();
            j.second.erase(j.second.begin());
            int cand2 = *j.second.begin();
            j.second.erase(j.second.begin());
            used[cand1] = true;
            used[cand2] = true;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

