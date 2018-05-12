#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int dp[1000100];
vector<int> primes;

int go(int x)
{
	int cnt = 0;
	for (auto i : primes) {
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
	}

	if (x != 1)
		cnt++;
	return cnt;
}

void buildPrimes()
{
	bool isPrime[1111];
	fill(isPrime, isPrime + 1111, true);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 1111; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i * i; j < 1111; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void buildPrefix()
{
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i < 1000001; i++) {
		dp[i] = dp[i - 1] + go(i);
	}

	// for (int i = 0; i < 10; i++)
	// 	printf("%d %d\n", i, dp[i]);
}

int main()
{
	// build prime
	buildPrimes();

	// build prefix sum
	buildPrefix();

	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", dp[n]);
	}

	return 0;
}
