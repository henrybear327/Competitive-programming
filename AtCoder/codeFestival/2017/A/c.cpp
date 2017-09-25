#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);

    int cnt[5] = {0};
    // 4
    cnt[4] = (h / 2) * (w / 2);

    // 2
    if (h % 2 == 1)
        cnt[2] += w / 2;

    if (w % 2 == 1)
        cnt[2] += h / 2;

    // 1
    cnt[1] = (h % 2) && (w % 2);

    int freq[26] = {0};
    for (int i = 0; i < h; i++) {
        char inp[1111];
        scanf("%s", inp);
        for (int j = 0; j < w; j++) {
            int val = inp[j] - 'a';
            freq[val]++;
        }
    }

    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            while (cnt[4] > 0 && freq[i] >= 4) {
                cnt[4]--;
                freq[i] -= 4;
            }
            while (cnt[2] > 0 && freq[i] >= 2) {
                cnt[2]--;
                freq[i] -= 2;
            }
            while (cnt[1] > 0 && freq[i] >= 1) {
                cnt[1]--;
                freq[i] -= 1;
            }

            if (freq[i] > 0)
                ok = false;
        }
    }

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
