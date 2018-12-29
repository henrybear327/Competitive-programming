#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

typedef pair< pair<ll, ll>, ll> iii;
int main()
{
    int n, b;
    scanf("%d %d", &n, &b);

    vector<iii> inp;
    for(int i = 0; i < n; i++) {
	ll x, y;
	scanf("%lld %lld", &x, &y);
	inp.push_back(make_pair(make_pair(x, y), i));
    }

    queue<iii> q;
    ll ans[n];
    for(int i = 0; i < n; i++)
	ans[i] = INT_MIN;
    ll start, end = inp[0].first.first;
    for(int i = 0; i < n; i++) {
	int ii = i;
	iii cur = inp[i];
	bool used_queue = false;
	if(q.empty() == false) {
	    used_queue = true;
	    cur = q.front();
	    q.pop();
	    ii = cur.second;
	}

	if(ans[ii] != INT_MIN) 
	    continue;

	//printf("%lld %lld %lld\n", cur.first.first, cur.first.second, cur.second);
	start = max(end, cur.first.first);
	end = start + cur.first.second;
	ans[ii] = end;
	
	bool inside = false;
	while(i + 1 < n && inp[i + 1].first.first < end) {
	    inside = true;
	    i++;
	    if((int)q.size() < b) {
		//printf("q %lld %lld %lld\n", inp[i].first.first, inp[i].first.second, inp[i].second);
		q.push(inp[i]);
	    } else {
		//printf("-1 %lld %lld %lld\n", inp[i].first.first, inp[i].first.second, inp[i].second);
		ans[i] = -1;
	    }
	}
	if(used_queue == true && inside == false)
	    i--;
	else
	    i = inside == true ? i - 1 : i;
    }

    while(q.empty() == false) {
	start = end;
	end = start + q.front().first.second;
	ans[q.front().second] = end;
	q.pop();
    }

    for(int i = 0; i < n; i++) {
	printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
