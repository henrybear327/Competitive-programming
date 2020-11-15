#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    map<int , ll> inp;
    for(int i = 0; i < n; i++) {
        int s, t, p;
        scanf("%d %d %d", &s, &t, &p);

        inp[s] += p;
        inp[t] += -p;
    }

    ll mx = 0;
    ll acc = 0;
    for(auto i : inp) {
        acc += i.second;
        mx = max(mx, acc);
    }

    if(mx > w) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
