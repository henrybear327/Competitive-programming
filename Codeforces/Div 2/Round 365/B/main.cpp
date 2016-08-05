#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	ll val[n], sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &val[i]);
		sum += val[i];
	}
	
	ll ans = 0;
	// ring
	for(int i = 0; i < n; i++)
		ans += val[i] * val[(i + 1) % n];
	
	//capital
	set<int> cap;
	for(int i = 0; i < k; i++) {
		int num;
		scanf("%d", &num);

		cap.insert(num - 1);
	}
	
	ll prev = 0;
	for(auto i : cap) {
		ll tmp = sum;
		tmp = tmp - val[(i + 1) % n] - val[(i - 1 + n) % n] - val[i];
		
		ll cur = val[i] * tmp;
		cur = cur - val[i] * prev;
		
		if(i != 0 && cap.find(i - 1) != cap.end())
			cur += val[i - 1] * val[i];

		if(i == n - 1 && cap.find(0) != cap.end())
			cur += val[i] * val[0];

		ans += cur;

		prev += val[i];
	}

	printf("%lld\n", ans);
	
    return 0;
}
