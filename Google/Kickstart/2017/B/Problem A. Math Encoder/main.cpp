#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> inp;
void input()
{
	scanf("%d", &n);

	inp.clear();

	for(int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		inp.push_back(tmp);
	}
}

typedef long long ll;

ll mod = (int)1e9 + 7;

ll table[11111];
void preprocess()
{
	table[0] = 1;
	table[1] = 2;
	for(int i = 2; i <= 10001; i++) {
		table[i] = table[i - 1] * 2 % mod;
	}
}

void solve()
{
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ans += (inp[j] - inp[i]) * table[j - i - 1];
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
}

int main()
{	
	int ncase, cnt = 1;
	scanf("%d", &ncase);
	
	preprocess();
	while(ncase--) {
		input();
		printf("Case #%d: ", cnt++);
		solve();
	}


	return 0;
}
