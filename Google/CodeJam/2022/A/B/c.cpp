#include <bits/stdc++.h>

using namespace std;

vector<string> cand;
mt19937 rng(9487);

void solve()
{
    int ret = 8;
    printf("%s\n", cand[0].c_str());
    fflush(stdout);

    while (1) {
        scanf("%d", &ret);
        if (ret == 0)
            return;
        if (ret == -1)
            exit(1);

        string idx;
        for (int j = 0; j < 256; j++) {
            int c = 0;
            for (int i = 0; i < 8; i++)
                if (cand[j][i] == '1')
                    c++;

            if (c == ret) {
                idx = cand[j];
                break;
            }
        }
        printf("%s\n", idx.c_str());
        fflush(stdout);
    }
}

int main()
{
    for (int i = 0; i < 256; i++) {
        string str;
        for (int j = 0; j < 8; j++) {
            str += ((i >> j) & 1) + '0';
        }
        cand.push_back(str);
    }
    shuffle(cand.begin(), cand.end(), rng);

    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        solve();
    }

    return 0;
}
