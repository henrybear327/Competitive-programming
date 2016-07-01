#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> cache;
void gen(int level, int num, bool used[])
{
    if (level == n) {
        cache.push_back(num);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            gen(level + 1, num * 10 + i + 1, used);
            used[i] = 0;
        }
    }
}

bool used[50000];
int order[50000];
bool state;

bool check(int x, int y)
{
    int first[n], second[n];
    int tmp = cache[x];
    for (int i = 0; i < n; i++) {
        first[n - i - 1] = tmp % 10;
        tmp /= 10;
    }
    tmp = cache[y];
    for (int i = 0; i < n; i++) {
        second[n - i - 1] = tmp % 10;
        tmp /= 10;
    }

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && first[i] == second[i - 1])
            continue;
        else if (first[i] == second[i])
            continue;
        else if (i + 1 < n && first[i] == second[i + 1])
            continue;
        else
            return false;
    }
    return true;
}

void go(int cur, int cnt)
{
    if (cnt == (int)cache.size()) {
        state = false;
        for (int i = 0; i < (int)cache.size(); i++) {
            printf("%d\n", order[i]);
        }
    }

    if (used[cur] == true)
        return;
    // printf("%d %d\n", cur, cnt);
    used[cur] = true;
    order[cnt] = cache[cur];

    for (int i = 0; i < (int)cache.size(); i++) {
        if (state == true && check(cur, i) == true) {
            go(i, cnt + 1);
        }
    }
    used[cur] = false;
}

int main()
{
    scanf("%d", &n);

    // generate the n! list
    memset(used, 0, sizeof(used));
    gen(0, 0, used);

    // gen the ans
    memset(used, 0, sizeof(used));
    memset(order, -1, sizeof(order));
    state = true;
    go(0, 0);

    return 0;
}
