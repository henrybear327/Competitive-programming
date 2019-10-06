#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    deque<int> l;
    set<int> pos;
    for (int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);

        if (pos.find(id) != pos.end())
            continue;

        if ((int)pos.size() == k) {
            pos.erase(l.back());
            l.pop_back();
        }

        l.push_front(id);
        pos.insert(l.front());
    }

    printf("%d\n", (int)l.size());
    for (auto i : l)
        printf("%d ", i);

    return 0;
}
