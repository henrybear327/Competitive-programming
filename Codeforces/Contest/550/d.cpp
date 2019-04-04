#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Operation {
    int op, i, j;
};

int main()
{
    int n;
    scanf("%d", &n);
    int inp[n];
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]), cnt[inp[i]]++;

    int mx = 0, who = -1;
    for (auto i : cnt) {
        if (i.second > mx) {
            mx = i.second;
            who = i.first;
        }
    }

    vector<Operation> ans;
    for (int i = 0; i < n; i++) {
        if (inp[i] == who) {
            for (int j = i - 1; j >= 0 && inp[j] != who; j--) {
                if (inp[j] < inp[j + 1])
                    ans.push_back({1, j, j + 1});
                else
                    ans.push_back({2, j, j + 1});

                inp[j] = who;
            }

            for (int j = i + 1; j < n && inp[j] != who; j++) {
                if (inp[j - 1] < inp[j])
                    ans.push_back({2, j, j - 1});
                else
                    ans.push_back({1, j, j - 1});

                inp[j] = who;
            }
        }
    }

    printf("%d\n", (int)ans.size());
    if (ans.size() > 0)
        for (auto i : ans)
            printf("%d %d %d\n", i.op, i.i + 1, i.j + 1);

    return 0;
}
