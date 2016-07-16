#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define N 200010
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    long long  val[n];
    for(int i = 0; i < n; i++)
	scanf("%lld", &val[i]);
    sort(val, val + n);
    
    ii inp[N];
    for(int i = 0; i < k; i++) {
	int l, r;
	scanf("%d %d", &l, &r);
	
	inp[l].first++;
	inp[r].second++;
    }

    int sum = 0;
    vector<long long> type;
    for(int i = 1; i <= n; i++) {
	sum += inp[i].first;
	type.push_back(sum);
	sum -= inp[i].second;
    }

    sort(type.begin(), type.end());
    
    long long ans = 0;
    for(int i = 0; i < n; i++)
	ans += val[i] * type[i];
    printf("%lld\n", ans);

    return 0;
}
