#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char s1[n + 3], s2[n + 3];
    scanf("%s %s", s1, s2);

    int n1 = n, n2 = n;
    int q1 = 0, q2 = 0;
    map<char, set<int>> ss1, ss2;
    vector<ii> ans;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '?')
            q1++;
        ss1[s1[i]].insert(i);
        if (s2[i] == '?')
            q2++;
        ss2[s2[i]].insert(i);
    }
    n1 -= q1;
    n2 -= q2;

    for (auto &i : ss1) {
        if (i.first == '?')
            continue;
        if (auto j = ss2.find(i.first); j != ss2.end()) {
            if (j->first == '?')
                continue;
            int mn = min(i.second.size(), j->second.size());
            for (int k = 0; k < mn; k++) {
                ans.push_back({*i.second.begin(), *j->second.begin()});
                i.second.erase(i.second.begin());
                j->second.erase(j->second.begin());
            }
            n1 -= mn;
            n2 -= mn;
        }
    }

    {
        int mn = min(n1, q2);
        auto it = ss1.begin();
        for (int i = 0; i < mn;) {
            while (i < mn && it->second.size() > 0) {
                if (it->first == '?')
                    break;
                ans.push_back({*it->second.begin(), *ss2['?'].begin()});
                it->second.erase(it->second.begin());
                ss2['?'].erase(ss2['?'].begin());
                i++;
            }
            it++;
        }
        n1 -= mn;
        q2 -= mn;
    }
    {
        int mn = min(n2, q1);
        auto it = ss2.begin();
        for (int i = 0; i < mn;) {
            while (i < mn && it->second.size() > 0) {
                if (it->first == '?')
                    break;
                ans.push_back({*ss1['?'].begin(), *it->second.begin()});
                it->second.erase(it->second.begin());
                ss1['?'].erase(ss1['?'].begin());
                i++;
            }
            it++;
        }
        // ans += mn;
        n2 -= mn;
        q1 -= mn;
    }
    {
        // ans += min(q1, q2);
        int mn = min(ss1['?'].size(), ss2['?'].size());
        auto i = ss1['?'].begin(), j = ss2['?'].begin();
        for (int k = 0; k < mn; k++) {
            ans.push_back({*i, *j});
            i++;
            j++;
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d %d\n", i.first + 1, i.second + 1);

    return 0;
}
