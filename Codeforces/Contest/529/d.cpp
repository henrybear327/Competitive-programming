#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<int> inp[200010];

vector<int> attempt;
bool done;
void dfs(int u, int v, const int &start)
{
    if (v != inp[u][0] && v != inp[u][1]) {
        return;
    }

    if (u == start && attempt.size() > 0) {
        // print ans
        for (auto i : attempt)
            printf("%d ", i + 1);
        done = true;
        return;
    }
    int k = inp[u][0] == v ? inp[u][1] : inp[u][0];
    // printf("u = %d v = %d k = %d\n", u + 1, v + 1, k + 1);

    attempt.push_back(u);
    dfs(v, k, start);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        inp[i].push_back(a);
        inp[i].push_back(b);
    }

    // try 0, [0]
    {
        attempt.clear();
        done = false;
        int u = 0;
        int v = inp[0][0];

        dfs(u, v, u);
    }

    // try 0, [1]
    if (done == false) {
        attempt.clear();
        done = false;
        int u = 0;
        int v = inp[0][1];

        dfs(u, v, u);
    }

    return 0;
}
