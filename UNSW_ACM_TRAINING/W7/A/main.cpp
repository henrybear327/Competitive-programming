#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> pos;
	for(int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		if(tmp == 1)
			pos.push_back(i);
	}

	ll ans = 1;
	for(int i = 1; i < (int)pos.size(); i++) {
		ans *= pos[i] - pos[i - 1];
	}

	if(pos.size() == 0)
		ans = 0;

	printf("%lld\n", ans);

	return 0;
}
