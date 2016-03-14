#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);

        printf("Discarded cards:");
        while (!q.empty()) {
            if (q.size() == 1) {
                if (n == 1) // special case
                    printf("\n");
                printf("Remaining card: %d\n", q.front());
                break;
            } else {
                printf(" %d%c", q.front(), q.size() == 2 ? '\n' : ',');
                q.pop();

                int tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
    }

    return 0;
}
