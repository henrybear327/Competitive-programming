#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> odd, even;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);

        ans += num;
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int o = odd.size() - 1, e = even.size() - 1;
    int turn = even.size() > odd.size() ? 1 : 0;
    while (true) {
        if (turn == 1) {
            if (e < 0)
                break;
            ans -= even[e];
            e--;
        } else {
            if (o < 0)
                break;

            ans -= odd[o];
            o--;
        }

        turn ^= 1;
    }
    printf("%d\n", ans);

    return 0;
}
