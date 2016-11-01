#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<ii> inp;
	int sl = 0, sr = 0;
	for(int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);

		inp.push_back(ii(l, r));
		sl += l;
		sr += r;
	}

	int ans = abs(sl - sr);
	int idx = 0;
	for(int i = 0; i < n; i++) {
		int tmp = abs((sl - inp[i].first + inp[i].second) - (sr - inp[i].second + inp[i].first));
		if(tmp > ans) {
			idx = i + 1;
			ans = tmp;
		}
	}
	printf("%d\n", idx);
	
    return 0;
}
