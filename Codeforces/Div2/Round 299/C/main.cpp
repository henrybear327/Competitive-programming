#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define N 1000010
ll dp[N]; 
ll a, b, t, m;
bool check(int l, int mid)
{
	ll upper = t * min(m, (ll)mid - l + 1);
	ll tot = dp[mid] - dp[l - 1];
	
	int test1 = (t - a + b) / b + 1;  
	if(l <= test1 && test1 <= mid)
		return false;

	return upper >= tot;
}

int main()
{
	int n;
	scanf("%lld %lld %d", &a, &b, &n);
	// printf("%lld %lld\n", a, b);
	
	for(int i = 1; i < N; i++) 
		dp[i] = a + (i - 1) * b;
	for(int i = 2; i < N; i++) 
		dp[i] += dp[i - 1];

	for(int i = 0; i < n; i++) {
		int l;
		scanf("%d %lld %lld", &l, &t, &m);
		int orig = l;
		l--;
		int r = N + 1; // [l, r), 1-based
		//printf("%d %d\n", l, r);
		while(r - l > 1) {
			// TTTTTFFFFF
			int mid = (l + r) / 2;
			// printf("%d %d %d\n", l, r, mid);
			if(check(orig, mid) == true) 
				l = mid;
			else
				r = mid;
		}
		printf("%d\n", l == orig - 1 ? -1 : l);
	}
	
    return 0;
}
