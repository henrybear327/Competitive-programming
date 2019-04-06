#include <bits/stdc++.h>

using namespace std;

pair<string, string> solve()
{
    pair<string, string> ans;

    char inp[111];
    scanf("%s", inp);
    ans.first = inp;

    vector<int> pos;
    for (int i = 0; i < (int)ans.first.length(); i++) {
        if (ans.first[i] == '4') {
            pos.push_back(i);
            ans.first[i] = '2';
        }
    }

    ans.second += "2";
    for (int i = 1; i < (int)pos.size(); i++) {
        int diff = pos[i] - pos[i - 1];
        for (int j = 0; j < diff - 1; j++)
            ans.second += "0";
        ans.second += "2";
    }

    if (pos.back() != (int)ans.first.length() - 1) {
        for (int i = 0; i < (int)ans.first.length() - 1 - pos.back(); i++)
            ans.second += "0";
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        auto res = solve();
        printf("Case #%d: %s %s\n", i, res.first.c_str(), res.second.c_str());
    }
}
