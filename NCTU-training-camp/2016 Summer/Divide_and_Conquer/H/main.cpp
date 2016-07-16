#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    int a, b;
    scanf("%d %d %d %d", &n, &k, &a, &b);
    
    vector< pair<ll, int> > inp;
    for(int i = 0; i < n; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	inp.push_back(make_pair(u * a + v * b, i));
    }

    sort(inp.begin(), inp.end());
    
    ll sum = 0;
    int idx = 0;
    for(int i = 0; i < n; i++) {
	if(sum + inp[i].first <= k) {
	    sum += inp[i].first;
	    idx++;
	}
	if(sum > k)
	    break;
    }
    
    printf("%d\n", idx);
    for(int i = 0; i < idx; i++)
	printf("%d%c", inp[i].second + 1, i == idx ? '\n' : ' ');

    return 0;
}
