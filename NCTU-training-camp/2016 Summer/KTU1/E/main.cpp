#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);

    ll inp[n][n];
    ll sum = 0;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) {
	    scanf("%lld", &inp[i][j]);
	    sum += inp[i][j];
	}

    for(int i = 0; i < n; i++) {
	ll rsum = 0;
	for(int j = 0; j < n; j++) {
	    rsum += inp[i][j];
	}
	inp[i][i] = sum / (n - 1) - rsum;
    }

    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	    printf("%lld%c", inp[i][j], j == n - 1 ? '\n' : ' ');

    return 0;
}
