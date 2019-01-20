#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void print(long long &ans, int inp[], int n)
{
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d ", inp[i]);
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    vector<vector<int>> rem(m, vector<int>());
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        rem[inp[i] % m].push_back(i);
    }

    long long ans = 0;

    deque<int> q;
    // pass 1
    for (int i = 0; i < m; i++) {
        while ((int)rem[i].size() > n / m) {
            q.push_back(rem[i].back());
            rem[i].pop_back();
        }

        while ((int)q.size() > 0 && (int)rem[i].size() < n / m) {
            int val = inp[q.front()] % m;
            int diff = i - val;

            ans += diff;
            inp[q.front()] += diff;

            rem[i].push_back(q.front());

            q.pop_front();
        }
    }

    // pass 2
    for (int i = 0; i < m; i++) {
        while ((int)q.size() > 0 && (int)rem[i].size() < n / m) {
            int val = inp[q.back()] % m;
            int diff = i + m - val;

            ans += diff;
            inp[q.back()] += diff;

            rem[i].push_back(q.back());

            q.pop_back();
        }
    }

    print(ans, inp, n);

    return 0;
}
