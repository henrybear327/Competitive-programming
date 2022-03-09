#include <bits/stdc++.h>

using namespace std;

char inp[1000003];
int main()
{
    // at most 1 letter with odd count can exist
    scanf("%s", inp);

    int cnt[26] = {0};
    for (const auto &c : inp) {
        cnt[c - 'A']++;
    }

    int odd = 0, idx = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
            idx = i;
        }
    }
    if (odd > 1) {
        printf("NO SOLUTION\n");
    } else {
        for (int i = 0; i < 26; i++) {
            if (i != idx && cnt[i] > 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    printf("%c", i + 'A');
                }
            }
        }
        if (idx != -1) { // Oops condition...
            for (int i = 0; i < cnt[idx]; i++) {
                printf("%c", idx + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (i != idx && cnt[i] > 0) {
                for (int j = 0; j < cnt[i] / 2; j++) {
                    printf("%c", i + 'A');
                }
            }
        }
        printf("\n");
    }

    return 0;
}
