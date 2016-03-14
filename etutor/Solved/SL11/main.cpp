#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    while (a && b && (a % 10 == b % 10)) {
        a /= 10;
        b /= 10;
    }

    return a % 10 < b % 10;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        int inp[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &inp[i]);
        }
        sort(inp, inp + n, cmp);
        for (int i = 0; i < n; i++)
            printf("%d%c", inp[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
