#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 5005
ll inp[N];
ll pre[N];

inline ll sum(int l, int r)  // [l, r)
{
	if(l == r)
		return 0;

	l++;
	r++;
	return pre[r - 1] - pre[l - 1];
}

struct Point {
	int left, mid, right;
} pt;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &inp[i]);
	
	pre[0] = 0;
	for(int i = 1; i <= n; i++) { 
		pre[i] = pre[i - 1] + inp[i];
	}

	ll ans = INT_MIN;
	for(int mid = 0; mid <= n; mid++) {
		ll left = INT_MIN;
		int tl = -1;
		for(int i = 0; i <= mid; i++) {
			if(left < sum(0, i) - sum(i, mid)) {
				left = sum(0, i) - sum(i, mid);
				tl = i;
			}
		}

		ll right = INT_MIN;
		int tr = -1;
		for(int i = mid; i <= n; i++) {
			if(right < sum(mid, i) - sum(i, n)) {
				right = sum(mid, i) - sum(i, n);
				tr = i;
			}
		}
		// printf("%d %d %d %lld\n", tl, mid, tr, left + right);

		if(ans < left + right) {
			pt.left = tl;
			pt.mid = mid;
			pt.right = tr;
			ans = left + right;
		}		
	}

	printf("%d %d %d\n", pt.left, pt.mid, pt.right);

	return 0;
}
