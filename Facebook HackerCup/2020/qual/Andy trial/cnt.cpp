#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        int n;
        cin >> n;

        vector<char> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> cnt(2);
        for (int i = 0; i < n; i++) {
            if (a[i] == 'A')
                cnt[0] += 1;
            else
                cnt[1] += 1;

            if (cnt[0] >= 2 && cnt[1] == 1) {
                cnt[0] -= 1;
                cnt[1] -= 1;
            } else if (cnt[0] == 1 && cnt[1] >= 2) {
                cnt[0] -= 1;
                cnt[1] -= 1;
            }
        }

        cout << "Case #" << tc << ": ";
        if ((cnt[0] == 1 && cnt[1] == 0) || (cnt[0] == 0 && cnt[1] == 1))
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
