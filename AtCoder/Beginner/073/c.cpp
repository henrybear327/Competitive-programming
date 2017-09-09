#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    set<int> has;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (has.find(num) != has.end())
            has.erase(num);
        else
            has.insert(num);
    }

    printf("%d\n", (int)has.size());

    return 0;
}
