#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    ll inpX[x], inpY[y], inpZ[z];
    for (int i = 0; i < x; i++)
        scanf("%lld", &inpX[i]);
    for (int i = 0; i < y; i++)
        scanf("%lld", &inpY[i]);
    for (int i = 0; i < z; i++)
        scanf("%lld", &inpZ[i]);
    sort(inpZ, inpZ + z);
	
	// we generate all results between first 2 arrays O(x*y)
    ll cand[x * y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cand[i * x + j] = inpX[i] + inpY[j];
    sort(cand, cand + x * y); // O(x*y log(x*y))

    vector<ll> ans;
	// we take the first k elements, and generate all results, too
	// O(k * k)
    for (int xx = max(0, x * y - k); xx < x * y; xx++)
        for (int yy = max(0, z - k); yy < z; yy++) {
            // printf("xx %d yy %d\n", xx, yy);
            // printf("%lld %lld\n", cand[xx], inpZ[yy]);
            ans.push_back(cand[xx] + inpZ[yy]);
        }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    for (int xx = 0; xx < k; xx++) {
        printf("%lld\n", ans[xx]);
    }

    return 0;
}
