#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int k, n, s, p;
	cin >> k >> n >> s >> p;

	int person = n / s + (n % s > 0);
	int total = k * person;

	cout << total / p + (total % p > 0) << endl;

	return 0;
}
