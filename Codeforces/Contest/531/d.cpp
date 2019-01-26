#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    char inp[n + 3];
    scanf("%s", inp);

    int cnt[3] = {0};
    for (int i = 0; i < n; i++)
        cnt[inp[i] - '0']++;

    // 2 missing
    // we replace from the back -> as back as possible
    for (int i = n - 1; i >= 0 && cnt[2] < n / 3; i--) {
        if (inp[i] == '0' && cnt[0] > n / 3) {
            cnt[2]++;
            cnt[0]--;
            inp[i] = '2';
        } else if (inp[i] == '1' && cnt[1] > n / 3) {
            cnt[2]++;
            cnt[1]--;
            inp[i] = '2';
        }
    }

    // 0 missing
    // we replace from the front, as front as possible
    for (int i = 0; i < n && cnt[0] < n / 3; i++) {
        if (inp[i] == '1' && cnt[1] > n / 3) {
            cnt[0]++;
            cnt[1]--;
            inp[i] = '0';
        } else if (inp[i] == '2' && cnt[2] > n / 3) {
            cnt[0]++;
            cnt[2]--;
            inp[i] = '0';
        }
    }

    // 1 missing
    // sub 0 with 1 from the back
    for (int i = n - 1; i >= 0 && cnt[1] < n / 3; i--) {
        if (inp[i] == '0' && cnt[0] > n / 3) {
            cnt[0]--;
            cnt[1]++;
            inp[i] = '1';
        }
    }

    // sub 2 with 1 from the front
    for (int i = 0; i < n && cnt[1] < n / 3; i++) {
        if (inp[i] == '2' && cnt[2] > n / 3) {
            cnt[2]--;
            cnt[1]++;
            inp[i] = '1';
        }
    }

    printf("%s\n", inp);

    return 0;
}
