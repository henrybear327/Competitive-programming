#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

struct Data {
	ll x, y, z;
};

vector<Data> inp;	

ll ans_sum;
bool isOdd(ll mid)
{
	ll sum = 0;
	ll cnt = 0;
	for(int i = 0; i < (int)inp.size(); i++) {
		if( min(inp[i].y, mid) < inp[i].x)
			continue;

		ll tmp = (min(inp[i].y, mid) - inp[i].x) / inp[i].z + 1;

		if(inp[i].x <= mid && mid <= inp[i].y && (mid - inp[i].x) % inp[i].z == 0) 
			cnt++;
		sum += tmp;
	}

	ans_sum = cnt;
	return sum % 2 == 1;
}

int main()
{
	char str[10000];

	bool last = true;
	while(last) {
		inp.clear();
		while(1) {
			if(fgets(str, 10000, stdin) == NULL) {
				last = false;
				break;
			}

			if(str[0] == '\n')
				break;

			ll x, y, z;
			sscanf(str, "%lld %lld %lld", &x, &y, &z);
			inp.push_back(Data({x, y, z}));
		}

		if(inp.size() == 0)
			continue;

		ll l = 0, r = LLONG_MAX;
		while(r - l > 1) {
			ll mid = l + (r - l) / 2;

			// printf("%lld %lld %lld\n", l, mid, r);
			if(isOdd(mid))
				r = mid;
			else
				l = mid;
		}
		
		if(r == LLONG_MAX)
			printf("no corruption\n");
		else {
			isOdd(r);
			printf("%lld %lld\n", r, ans_sum); 
		}
	}
	return 0;
}
