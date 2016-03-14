#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int enemy[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &enemy[i]);

        int my[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &my[i]);

        sort(enemy, enemy + n);
        sort(my, my + n);

        int i = 0, j = 0, cnt = 0;
        while (i < n && j < n) {
            if (enemy[i] < my[j]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
