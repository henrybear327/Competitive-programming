#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n;
bool check(int inp[], int len, int total)
{
    int has[total + 1];
    memset(has, 0, sizeof(has));
    int type = 0;
    for (int i = 0; i < len; i++) {
        if (has[inp[i]] == 0)
            type++;
        has[inp[i]]++;
    }
    if (type == total)
        return true;

    for (int i = len; i < n; i++) {
        if (has[inp[i]] == 0)
            type++;
        has[inp[i]]++;

        has[inp[i - len]]--;
        if (has[inp[i - len]] == 0)
            type--;

        if (type == total)
            return true;
    }

    return false;
}

int main()
{
    scanf("%d", &n);

    // input
    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    // lisan
    map<int, int> lisan;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        if (lisan[inp[i]] == 0) {
            lisan[inp[i]] = idx++;
        }

        inp[i] = lisan[inp[i]];
    }

    int l = 1, r = n + 1; // [l, r)
    while (r - l > 1) {
        int mid = (l + r) / 2;

        // 0 0 0 1 1 1 1
        if (check(inp, mid, lisan.size()))
            r = mid;
        else
            l = mid;
    }

    printf("%d\n", r);

    return 0;
}
