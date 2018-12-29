#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;
vector<si> inp;

void check(string candidate)
{
    vector<si> l;
    for (int i = 1; i <= (int)candidate.length() - 1; i++) {
        l.push_back(si(candidate.substr(0, i), 0));
        l.push_back(si(candidate.substr(i), 1));
    }

    for (auto i : inp) {
        bool ok = false;
        for (auto j : l)
            if (i.first == j.first) {
                ok = true;
                break;
            }

        if (!ok)
            return;
    }

    sort(inp.begin(), inp.end(),
    [](const si a, const si b) {
        return a.second < b.second;
    });

    bool used[222] = {false};
    for (auto i : inp) {
        int idx = 0;
        for (auto j : l) {
            if (i.first == j.first && used[idx] == false) {
                used[idx] = true;
                cout << (j.second == 0 ? "P" : "S");
                break;
            }
            idx++;
        }
    }
    exit(0);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 2; i++) {
        string tmp;
        cin >> tmp;
        inp.push_back(si(tmp, i));
    }

    sort(inp.begin(), inp.end(), [](const si a, const si b) {
        return a.first.length() < b.first.length();
    });

    int l = 0, r = inp.size() - 1;

    check(inp[l].first + inp[r].first);
    check(inp[l].first + inp[r - 1].first);
    check(inp[l + 1].first + inp[r].first);
    check(inp[l + 1].first + inp[r - 1].first);
    check(inp[r].first + inp[l].first);
    check(inp[r].first + inp[l + 1].first);
    check(inp[r - 1].first + inp[l].first);
    check(inp[r - 1].first + inp[l + 1].first);

    return 0;
}
