#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mn, ll s, int inp[], int n)
{
	ll total = 0;
	for (int i = 0; i < n; i++)
		if (inp[i] >= mn)
			total += inp[i] - mn;
	if (total >= s)
		return true;
	return false;
}

int main()
{
	int n;
	ll s;
	scanf("%d %lld", &n, &s);

	int inp[n];
	int lb = -1, rb = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d", &inp[i]);
		rb = min(rb, inp[i]); // come on man, the ub must be the min of all cups!
	}

	rb++;
	while (rb - lb > 1) {
		int mid = (lb + rb) / 2;
		// oooxxxxxx
		if (check(mid, s, inp, n))
			lb = mid;
		else
			rb = mid;
	}

	printf("%d\n", lb);

	return 0;
}
