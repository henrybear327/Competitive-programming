#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    // split to 2 groups
    // 1, 1+ starso
    int n;
    scanf("%d", &n);

    vector<string> strs;
    string pre, suf;
    for (int i = 0; i < n; i++) {
        char inp[111];
        scanf("%s", inp);

        strs.push_back(inp);

        int len = strlen(inp);
        // get pre
        string tmp = "";
        for (int j = 0; j < len; j++) {
            if (strs[i][j] == '*') {
                tmp = strs[i].substr(0, j);
                if (pre.size() < tmp.size())
                    pre = tmp;

                break;
            }
        }

        // get suf
        tmp = "";
        for (int j = len - 1; j >= 0; j--) {
            if (strs[i][j] == '*') {
                tmp = strs[i].substr(j + 1, len);
                if (suf.size() < tmp.size())
                    suf = tmp;

                break;
            }
        }
    }

    // check prefix/suffix
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)strs[i].size(); j++) {
            if (strs[i][j] == '*') {
                for (int k = 0; k < j; k++) {
                    if (strs[i][k] != pre[k]) {
                        ok = false;
                    }
                }
                break;
            }
        }

        for (int j = strs[i].size() - 1; j >= 0; j--) {
            if (strs[i][j] == '*') {
                int idx = suf.size() - 1;
                for (int k = (int)strs[i].size() - 1; k > j; k--) {
                    if (strs[i][k] != suf[idx]) {
                        ok = false;
                    }
                    idx--;
                }
                break;
            }
        }
    }

    // make mid
    if (ok) {
        string mid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)strs[i].size(); j++) {
                if (strs[i][j] == '*') {
                    for (int k = (int)strs[i].size() - 1; k >= 0; k--) {
                        if (strs[i][k] == '*') {
                            for (int x = j + 1; x < k; x++) {
                                if (strs[i][x] != '*')
                                    mid += strs[i][x];
                            }

                            break;
                        }
                    }
                    break;
                }
            }
        }

        printf("%s", (pre + mid + suf).c_str());
    } else {
        printf("*");
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }

    return 0;
}
