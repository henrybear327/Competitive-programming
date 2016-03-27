#include <cstdio>
#include <bitset>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        bitset<1000010> data;
        bool conflict = false;

        for (int i = 0; i < n; i++) {
            int s, e;
            scanf("%d %d", &s, &e);

            for (int j = s + 1; j <= e; j++) {
                if (data.test(j) == false) {
                    data.set(j);
                } else {
                    conflict = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int s, e, interval;
            scanf("%d %d %d", &s, &e, &interval);

            while (s <= 1000000) {
                for (int j = s + 1; j <= e && j <= 1000000; j++) {
                    if (data.test(j) == false) {
                        data.set(j);
                    } else {
                        conflict = true;
                    }
                }
                s += interval;
                e += interval;
            }
        }

        if (conflict)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
    }

    return 0;
}
