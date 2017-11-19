// binary search
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

char inp[100010];
int n;
bool check(int mid)
{
    int cnt[26] = {0};
    int has[26] = {0};
    for (int i = 0; i < mid; i++)
        cnt[inp[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (cnt[i] > 0)
            has[i]++;

    for (int i = mid; i < n; i++) {
        cnt[inp[i] - 'a']++;
        cnt[inp[i - mid] - 'a']--;

        for (int j = 0; j < 26; j++)
            if (cnt[j] > 0)
                has[j]++;
    }

    for (int i = 0; i < 26; i++)
        if (has[i] >= n - mid + 1)
            return true;
    return false;
}

int main()
{
    scanf("%s", inp);

    n = strlen(inp);
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%d\n", r);

    return 0;
}
