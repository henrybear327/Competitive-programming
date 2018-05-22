#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define N 100010
int n, m;
ll city[N], tower[N];

bool check(ll mid)
{
    //printf("mid %lld\n", mid);
    for(int i = 0; i < n; i++) {
        // lowerbound
        ll target = city[i] + mid;

        int l = 0, r = m;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(tower[mid] <= target)
                l = mid;
            else
                r = mid;
        }

        ll num = tower[l];
        if(city[i] - mid <= num && num <= city[i] + mid)
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
	    scanf("%lld", &city[i]);

	for(int i = 0; i < m; i++)
        scanf("%lld", &tower[i]);

    //ll l = -1, r = (ll)1e9 * 2LL + 10;
    ll l = -1, r = (ll)1e9 * 2LL + 10;
    // FFFTTTT
    while(r - l > 1) {
        ll mid = l + (r - l) / 2;

        if(check(mid))
            r = mid;
        else
            l = mid;
    }

    printf("%lld\n", r);

    return 0;
}
