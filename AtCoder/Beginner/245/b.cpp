#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    set<int> inp;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inp.insert(num);
    }

    int cnt = 0;
    for (const auto &num : inp) {
        if (cnt != num) {
            break;
        }
        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
