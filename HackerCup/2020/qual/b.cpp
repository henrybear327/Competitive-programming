#include <bits/stdc++.h>

using namespace std;

// observation 1
// if we have different element in the array
// we can always do elimination

// observation 2
// every move, count of A and B will both reduce by exactly 1

// observation 3
// the sequence of how we do elimination is not relevant

// solution
// eventual A and B count must be 0, 1 or 1, 0
void solve()
{
    int n;
    scanf("%d", &n);

    int cnt[2] = {0};

    char inp[n + 2];
    scanf("%s", inp);
    for (int i = 0; i < n; i++)
        cnt[inp[i] - 'A']++;

    /*
    cnt[0] -= n / 2;
    cnt[1] -= n / 2;

    if ((cnt[0] == 1 || cnt[1] == 1) && (cnt[0] != cnt[1]))
        printf("Y\n");
    else
        printf("N\n");
    */
    if (abs(cnt[0] - cnt[1]) == 1)
        printf("Y\n");
    else
        printf("N\n");
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
