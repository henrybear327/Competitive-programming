#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (k == 1) {
        printf("%d\n", n);
        return 0;
    } 

    set<int, greater<int>> s;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);

        s.insert(cur);
    }

    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        int cand = *i;
        if (cand % k != 0) {
            continue;
        }

        set<int>::iterator it;
        if ((it = s.find(cand / k)) != s.end()) {
            s.erase(it);
        }
    }

    printf("%d\n", (int)s.size());

    return 0;
}
