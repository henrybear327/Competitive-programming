#include <cstdio>
#include <map>

using namespace std;

bool graph[1010][1010];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        graph[a][b] = graph[b][a] = true;
    }

    int color[1010] = {0};

    int cnt = 2;  // After first one
    color[0] = 1; // First one is color 1

    for (int i = 1; i < n; i++) {
        bool first = true;
        bool do_not_use[1010] = {0};
        int same_color = 0;
        for (int j = 0; j < i; j++) {
            if (graph[i][j] == true) {
                do_not_use[color[j]] = true;
            } else {
                if (first) {
                    first = !first;
                    same_color = color[j];
                } else {
                    if (same_color != color[j]) {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }

        if (same_color == 0) {
            for (int i = 1; i < cnt; i++) {
                if (do_not_use[i] == same_color) {
                    printf("-1\n");
                    return 0;
                }
            }
            color[i] = cnt;
            cnt++;
        } else {
            color[i] = same_color;
        }
    }

    if (cnt - 1 > k)
        printf("-1\n");
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (graph[i][j] == true) {
                        if (color[i] == color[j]) {
                            printf("-1\n");
                            return 0;
                        }
                    } else {
                        if (color[i] != color[i]) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d%c", color[i], i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
