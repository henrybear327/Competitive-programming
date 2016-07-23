#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define EPS 1e-9
int main()
{
    int n, l, v1, v2, k;
    scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);

    double ans = (double)n * (l - v2 * k - 1) / (double)(n - 1 - v2 * k);
    printf("%.15f\n", ans);
	
    return 0;
}
