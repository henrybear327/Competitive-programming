#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int s, b;
    scanf("%d %d", &s, &b);

    int attack[s];
    for (int i = 0; i < s; i++) {
        scanf("%d", &attack[i]);
    }

    map<int, int> base;
    for (int i = 0; i < b; i++) {
        int defense, gold;
        scanf("%d %d", &defense, &gold);
        base[defense] += gold;
    }

    int prev = 0;
    for (auto &i : base) {
        i.second += prev;
        prev = i.second;
    }

    for (auto i : attack) {
        auto it = base.lower_bound(i + 1); // good trick
        if (it != base.begin()) {
            it--;
            printf("%d ", it->second);
        } else {
            printf("0 ");
        }

        /*
                auto it = base.lower_bound(i);

                if (it == base.end()) {
            printf("%d ", base.rbegin()->second);
        } else {
            if (it->first <= i)
                printf("%d ", it->second);
            else {
                if (it == base.begin())
                    printf("0 ");
                else {
                    it--;
                    printf("%d ", it->second);
                }
            }
        }
                */
    }

    return 0;
}
