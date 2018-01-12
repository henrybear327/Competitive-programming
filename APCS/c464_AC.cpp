#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Data {
	int w, f;
};

bool cmp(const Data& a, const Data &b)
{
	// return a.f * b.w < b.f * a.w;
	return a.w * b.f < b.w * a.f;
}

int main()
{
	int n;
	scanf("%d", &n);

	Data data[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i].w);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i].f);
	}
	sort(data, data + n, cmp);

	ll ans = 0, accum = 0;
	for(int i = 0; i < n - 1; i++) {
		accum += data[i].w;
		ans += accum * data[i + 1].f;
	}

	printf("%lld\n", ans);

	return 0;
}
