#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char inp[20];
        scanf("%s", inp);

        int cnt = 0;
        vector< pair<int, int> > ans;
        for (int j = 1; j <= 12; j++) {
            if ((12 % j) == 0) {
                bool final = false;

                int group_size = 12 / j;
                for (int l = 0; l < group_size; l++) {
                    bool ok = true;
                    for (int k = 0; k < j; k++) {
                        if (inp[k * group_size + l] == 'O') {
                            ok = false;
                        }
                    }
                    if (ok == true)
                        final = true;
                }

                if (final == true) {
                    ans.push_back(make_pair(j, 12 / j));
                    cnt++;
                }
            }
        }

        printf("%d%c", cnt, cnt == 0 ? '\n' : ' ');
        for (int i = 0; i < (int)ans.size(); i++)
            printf("%dx%d%c", ans[i].first, ans[i].second,
                   i == (int)ans.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
