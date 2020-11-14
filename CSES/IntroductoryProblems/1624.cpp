#include <bits/stdc++.h>

using namespace std;
char inp[8][8 + 3];
int placement[8] = {0};
bool seen[8] = {false};

bool check(int idx)
{
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx; j++) {
            if (i == j)
                continue;

            // same col -> impossible

            // same row -> impossible

            // diagnal
            if (abs(i - j) == abs(placement[j] - placement[i]))
                return false;
        }
    }

    return true;
}

int ans = 0;

void dfs(int idx)
{
    if (idx == 8) {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (seen[i])
            continue;
        if (inp[idx][i] == '*')
            continue;

        placement[idx] = i;
        seen[i] = true;
        if (check(idx + 1)) // what a bug
            dfs(idx + 1);
        seen[i] = false;
        placement[idx] = -1;
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
        scanf("%s", inp[i]);

    dfs(0);

    printf("%d\n", ans);

    return 0;
}
