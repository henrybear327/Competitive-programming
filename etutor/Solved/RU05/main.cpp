#include <cstdio>
#include <algorithm>

using namespace std;

int list[60];

bool check(int i, int j, int k)
{
    int a = list[i], b = list[j], c = list[k];
    return a + b > c && a + c > b && b + c > a;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d", &list[i]);

        sort(list, list + n);

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (check(i, j, k))
                        printf("%d %d %d\n", list[i], list[j], list[k]);
                }
            }
        }
    }

    return 0;
}
