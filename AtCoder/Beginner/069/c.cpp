#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	scanf("%lld", &n);

	ll inp[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &inp[i]);

	ll cnt[3] = {0};
	for(int i = 0; i < n; i++) {
		if(inp[i] % 4 == 0) 
			cnt[2]++;
		else if(inp[i] % 2 == 0)
			cnt[1]++;
	}
	
	bool ok = false;
	if(cnt[2] * 2 >= n)
		ok = true;
	else {
		n -= cnt[2] * 2;
		if(n == 1 && cnt[2] > 0)
			ok = true;
		if(n > 1 && cnt[1] >= n)
			ok = true;
	}

	printf("%s\n", ok ? "Yes" : "No");

	return 0;
}
