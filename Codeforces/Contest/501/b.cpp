#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3], target[n + 3];
    scanf("%s %s", inp, target);

    bool ok = true;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        // find first occurrence
        int occ = -1;
        for (int j = i; j < n; j++) {
            if (target[i] == inp[j]) {
                occ = j;
                break;
            }
        }

        if (occ == -1) {
            ok = false;
            break;
        }

        // bubble sort
        for (int j = occ - 1; j >= i; j--) {
            ans.push_back(j);
            swap(inp[j], inp[j + 1]);
        }
    }

    if (ok) {
        printf("%d\n", (int)ans.size());
        for (auto i : ans)
            printf("%d ", i + 1);
    } else {
        printf("-1\n");
    }

    return 0;
}
