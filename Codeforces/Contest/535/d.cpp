#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<char, int> ii;

const char *c = "RGB";

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n];
    scanf("%s", inp);

    vector<ii> compressed;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (inp[i - 1] == inp[i])
            cnt++;
        else {
            compressed.push_back(ii(inp[i - 1], cnt));
            cnt = 1;
        }
    }
    compressed.push_back(ii(inp[n - 1], cnt));

    int ans = 0;
    int idx = 0;
    for (int i = 0; i < (int)compressed.size(); i++) {
        int sz = compressed[i].second;
        char replaceWith;
        if (sz % 2 == 1) {
            replaceWith = c[0];
            if (replaceWith == compressed[i].first)
                replaceWith = c[1];
        } else {
            for (int j = 0; j < 3; j++) {
                if (c[j] != compressed[i].first && i == (int)compressed.size() - 1)
                    replaceWith = c[j];
                else if (c[j] != compressed[i].first &&
                         i < (int)compressed.size() - 1 &&
                         c[j] != compressed[i + 1].first)
                    replaceWith = c[j];
            }
        }
        ans += sz / 2;
        for (int j = 0; j < sz; j++) {
            if (j % 2 == 1)
                inp[idx] = replaceWith;
            idx++;
        }
    }

    printf("%d\n%s\n", ans, inp);

    return 0;
}
