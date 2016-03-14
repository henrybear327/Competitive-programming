#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2 && (a || b)) {
        set<int> aa, bb;
        for (int i = 0; i < a; i++) {
            int tmp;
            scanf("%d", &tmp);

            aa.insert(tmp);
        }

        for (int i = 0; i < b; i++) {
            int tmp;
            scanf("%d", &tmp);

            bb.insert(tmp);
        }

        int ans = 0;
        for (auto it = aa.begin(); it != aa.end(); it++) {
            if (bb.find(*it) != bb.end()) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
