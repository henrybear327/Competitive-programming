#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char inp[n + 3];
    scanf("%s", inp);

    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        int start = i, end = i;
        while (end + 1 < n && inp[end + 1] == inp[start])
            end++;

        int acc = end - start + 1;
        cnt[inp[start] - 'a'] += acc / k;

        i = end;
    }

    printf("%d\n", *max_element(cnt, cnt + 26));

    return 0;
}
