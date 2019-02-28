#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool isSuffix(const string &str, const string &cand)
{
    if (str.length() > cand.length())
        return false;

    for (int idx = 0, i = cand.length() - str.length(); i < (int)cand.length();
         idx++, i++)
        if (str[idx] != cand[i])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    unordered_map<string, set<string>> inp;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            string num;
            cin >> num;

            inp[name].insert(num);
        }
    }

    unordered_map<string, vector<string>> ans;
    for (auto entry : inp) {
        auto name = entry.first;
        auto orig = entry.second;

        vector<string> data(orig.begin(), orig.end());
        sort(data.begin(), data.end(), [](const string &a, const string &b) {
            if (a.length() == b.length())
                return a < b;
            return a.length() < b.length();
        });

        int sz = data.size();
        for (int i = 0; i < sz; i++) {
            bool skip = false;
            for (int j = i + 1; j < sz; j++) {
                if (isSuffix(data[i], data[j]))
                    skip = true;
            }
            if (skip)
                continue;

            ans[name].push_back(data[i]);
        }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.first << " " << i.second.size();
        for (auto j : i.second)
            cout << " " << j;
        cout << "\n";
    }

    return 0;
}
