#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1000010
bool prime[N];
vector<ll> p;

int main()
{
	// preprocessing
	fill(prime, prime + N, true);
	prime[0] = prime[1] = false;
	for(ll i = 2; i < N; i++) {
		if(prime[i] == true) {
			p.push_back(i);
			for(ll j = i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}

	unordered_set<ll> res;
	for(auto i: p) {
		res.insert(i * i);
	}
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		ll num;
		scanf("%lld", &num);
	
		if(res.find(num) != res.end())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
