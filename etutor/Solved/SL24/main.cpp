#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        int ans[3] = {0};
        while (n--) {
            int tmp;
            scanf("%d", &tmp);
            ans[tmp % 3]++;
        }

        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
    return 0;
}
