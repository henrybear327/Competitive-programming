#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[100010];
    scanf("%s", inp);

    int n;
    scanf("%d", &n);

    bool isNormal = true;
    string head, tail;
    auto solve = [&]() {
        for (int i = 0; i < n; i++) {
            int op;
            scanf("%d", &op);

            if (op == 1) {
                isNormal = !isNormal;
            } else {
                // op == 2
                int pos;
                scanf("%d", &pos);

                char c[10];
                scanf("%s", c);

                if (pos == 1) {
                    if (isNormal)
                        head += c;
                    else
                        tail += c;
                } else {
                    if (isNormal)
                        tail += c;
                    else
                        head += c;
                }
            }
        }

        reverse(head.begin(), head.end());
        string ans = head + inp + tail;
        if (isNormal == false)
            reverse(ans.begin(), ans.end());
        printf("%s\n", ans.c_str());
    };

    solve();

    return 0;
}
