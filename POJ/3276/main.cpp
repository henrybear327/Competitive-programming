#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int inp[5555];
int check(int k)
{
    bool hasChange[5555] = {false};
    int flipCnt = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i - k >= 0)
            if (hasChange[i - k] == true)
                cnt--;

        if ((inp[i] + cnt) % 2 == 0)
            continue;

        if (i + k > n)
            return 0x3f3f3f3f;
        flipCnt++;
        hasChange[i] = true;
        cnt++;
    }

    return flipCnt;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char tmp[10];
        scanf("%s", tmp);

        if (tmp[0] == 'F')
            inp[i] = 0;
        else
            inp[i] = 1;
    }

    int mn = 0x3f3f3f3f;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        int cnt = check(i);

        if (cnt < mn) {
            mn = cnt;
            idx = i;
        }
    }
    printf("%d %d\n", idx, mn);

    return 0;
}
