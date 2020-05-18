#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, char> ii;

void solve()
{
    map<char, int> mapping;
    set<int> s;

    for (int _ = 0; _ < 10000; _++) {
        char m[22222], r[22222];
        scanf("%s %s", m, r);

        int rLen = strlen(r);
        for (int i = 0; i < rLen; i++) {
            s.insert(r[i] - 'A');
        }

        int mLen = strlen(m);
        if (mLen == rLen) {
            if (mapping.find(r[0]) != mapping.end()) {
                mapping[r[0]] = min(m[0] - '0', mapping[r[0]]);
            } else {
                mapping[r[0]] = m[0] - '0';
            }
        }
    }

    ii ret[mapping.size()];
    int idx = 0;
    for (auto i : mapping)
        ret[idx++] = {i.second, i.first};
    sort(ret, ret + idx);

    string ans;
    for (int i = 0; i < mapping.size(); i++) {
        s.erase(s.find(ret[i].second - 'A'));
    }

    ans += *s.begin() + 'A';
    for (int i = 0; i < mapping.size(); i++) {
        ans += ret[i].second;
    }

    printf("%s\n", ans.c_str());
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        int u;
        scanf("%d", &u);
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
