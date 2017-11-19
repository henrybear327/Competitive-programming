#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    scanf("%s", inp);

    int cnt[4] = {0};
    for (int i = 0; i < n; i++) {
        char c = inp[i];
        if (c == 'L')
            cnt[0]++;
        else if (c == 'R')
            cnt[1]++;
        else if (c == 'U')
            cnt[2]++;
        else
            cnt[3]++;
    }

    printf("%d\n", min(cnt[0], cnt[1]) * 2 + min(cnt[2], cnt[3]) * 2);

    return 0;
}
