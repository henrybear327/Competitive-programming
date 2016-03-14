#include <cstdio>
#include <cstring>

int main()
{
    int h, l;
    while (scanf("%d %d", &h, &l) == 2 && h != 0 && l != 0) {
        int cnt = 0;
        bool flag[h];
        memset(flag, false, sizeof(flag));

        for (int i = 0; i < l; i++) {
            int curr;
            scanf("%d", &curr);

            curr = h - curr;
            for (int j = 0; j < h; j++) {
                if (flag[j] == false && j < curr) {
                    flag[j] = true;
                    cnt++;
                } else if (flag[j] == true && j >= curr) {
                    flag[j] = false;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
