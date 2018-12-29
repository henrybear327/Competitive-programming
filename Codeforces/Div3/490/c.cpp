#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char inp[n + 2];
    scanf("%s", inp);

    bool mask[n + 2];
    memset(mask, false, sizeof(mask));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; k > 0 && j < n; j++) {
            if (inp[j] == i + 'a' && mask[j] == false) {
                mask[j] = true;
                k--;
            }
        }
    }

    char ans[n + 2];
    memset(ans, '\0', sizeof(ans));

    int idx = 0;
    for (int i = 0; i < n; i++)
        if (mask[i] == false)
            ans[idx++] = inp[i];

    printf("%s\n", ans);

    return 0;
}
