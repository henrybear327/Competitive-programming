#include <bits/stdc++.h>

using namespace std;

#define N 100010
bool p[N];

typedef long long ll;
vector<int> prime;
void init()
{
    fill(p, p + N, true);
    p[0] = p[1] = false;

    for(ll i = 2; i < N; i++)  {
	if(p[i] == false)
	    continue;
	for(ll j = i * i; j < N; j += i) {
	    p[j] = false;
	}
    }

    for(int i = 2; i < N; i++)
	if(p[i] == true)
	    prime.push_back(i);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    init();
    
    ll col[m], row[n];
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    int cur;
	    scanf("%d", &cur);

	    int val = *lower_bound(prime.begin(), prime.end(), cur) - cur;
	    // printf("%d\n", val);

	    row[i] += val;
	    col[j] += val;
	}
    }
    
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) 
	ans = min(ans, row[i]);
    for(int j = 0; j < m; j++)
	ans = min(ans, col[j]);
    printf("%lld\n", ans);

    return 0;
}
