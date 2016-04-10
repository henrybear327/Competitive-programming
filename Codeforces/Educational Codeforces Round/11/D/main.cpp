#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    pair<long long, long long> inp[2010];
    map<pair<long long, long long>, long long > mid;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
	long long a, b;
	//scanf("%lld %lld", &a, &b);
	scanf("%I64d %I64d", &a, &b);

	for(int j = 0; j < i; j++) {
	    long long c = inp[j].first, d = inp[j].second;
	    if(mid[make_pair((a + c), (b + d))] != 0)
		ans += mid[make_pair((a + c), (b + d))];
	    mid[make_pair((a + c), (b + d))]++;
	}
	inp[i] = make_pair(a, b);
    }
    
    /*
    long long  ans = 0;
    for(auto i : mid) {
	ans += (i.second * (i.second - 1) / 2);
    }
    */
    //printf("%lld\n", ans);
    printf("%I64d\n", ans);

    return 0;
}
