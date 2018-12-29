#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string orig;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        orig.push_back(tmp + '0');
    }
    // printf("input %s\n", orig.c_str());

    string prev = orig;
    int ans = 0;
    while (1) {
        string tmp = orig;
        for (int i = 1; i < n - 1; i++) {
            int cnt = 0;
            for (int j = i - 1; j <= i + 1; j++) {
                if (orig[j] == '0') {
                    cnt++;
                }
            }

            if (cnt >= 2)
                tmp[i] = '0';
            else
                tmp[i] = '1';
        }

        // printf("tmp %s\n", tmp.c_str());
        // printf("prev %s\n", prev.c_str());

        if (tmp == orig)
            break;

        ans++;

        orig = tmp;
        prev = orig;
    }

    printf("%d\n", ans);
    int len = orig.size();
    for (int i = 0; i < len; i++) {
        printf("%c%c", orig[i], i == len - 1 ? '\n' : ' ');
    }

    return 0;
}
