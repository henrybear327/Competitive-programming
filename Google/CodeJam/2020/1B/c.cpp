#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int tot = 0;
vector<int> go(vector<int> cur, int i, int j)
{
    vector<int> newState;
    for (int k = i + 1; k <= j; k++)
        newState.push_back(cur[k]);
    for (int k = 0; k <= i; k++)
        newState.push_back(cur[k]);
    for (int k = j + 1; k < tot; k++)
        newState.push_back(cur[k]);
    return newState;
}

vector<int> go2(vector<int> cur, int i, int j)
{
    // [0, i] [i + 1, j]

    // ab 0 1 -> ba
    // ba 1 0 -> ab

    // abb 1 2 -> bba
    //     j i
    // bba 2 1 -> abb
    vector<int> newState;
    for (int k = j - i; k < j - i + i + 1; k++)
        newState.push_back(cur[k]);
    for (int k = 0; k < j - i; k++)
        newState.push_back(cur[k]);
    for (int k = j + 1; k < tot; k++)
        newState.push_back(cur[k]);
    return newState;
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    tot = n * m;

    map<vector<int>, ii> step;
    queue<vector<int>> q;
    vector<int> init;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            init.push_back(j);

    q.push(init);
    step[init] = ii{-1, -1};

    while (q.size() > 0) {
        vector<int> cur = q.front();
        q.pop();

        // for (int i = 0; i < tot; i++)
        //  printf("%d%c", cur[i], i == tot - 1 ? '\n' : ' ');

        // check
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (cur[i * m + j] != i)
                    ok = false;
            }
        if (ok) {
            // printf("OK!\n");
            vector<ii> ans;
            while (true) {
                ii trace = step[cur];
                if (trace.first == -1 && trace.second == -1)
                    break;
                ans.push_back(trace);

                // printf("%d %d\n", trace.first, trace.second);
                // for (int i = 0; i < tot; i++)
                //  printf("%d%c", cur[i], i == tot - 1 ? '\n' : ' ');
                cur = go2(cur, trace.first, trace.second);
                // for (int i = 0; i < tot; i++)
                //  printf("%d%c", cur[i], i == tot - 1 ? '\n' : ' ');
            }

            printf("%d\n", (int)ans.size());
            reverse(ans.begin(), ans.end());
            for (auto i : ans) {
                printf("%d %d\n", i.first + 1, i.second - i.first);
            }

            break;
        }

        // 1 2 1 2 1 2
        for (int i = 0; i < tot; i++)
            for (int j = i + 1; j < tot; j++) {
                // [0, i] [i + 1, j]
                vector<int> newState = go(cur, i, j);

                if (step.count(newState) == 0) {
                    step[newState] = ii{i, j};
                    q.push(newState);
                }
            }
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
