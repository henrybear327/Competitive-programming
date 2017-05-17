#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d", &n);

	vector<ll> cand;
	for(int i = 1; i <= 9; i++)
		cand.push_back(i);
	
	ll base = 10;
	for(int i = 0; i < 9; i++) {
		for(int j = 1; j <= 9; j++)
			cand.push_back(j * base);

		base *= 10;
	}

	for(auto i : cand) {
		if(i - n > 0) {
			printf("%lld\n", i - n);
			break;
		}
	}
		
	return 0;
}
