#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define N 100010
int n, k;
ll inp[N], pre[N];

ll minAns;
bool check(int mid) 
{
    for(int i = mid; i <= n; i++) {
	if(inp[i] * mid - (pre[i] - pre[i - mid]) <= k) {
	    minAns = inp[i];
	    return true;
	}
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    
    for(int i = 1; i <= n; i++)
	scanf("%lld", &inp[i]);
    sort(inp + 1, inp + n + 1);
    
    pre[0] = 0;
    for(int i = 1; i <= n; i++)
	pre[i] = pre[i - 1] + inp[i];

    int l = 0, r = n + 1;
    minAns = -1;
    while(r - l > 1) {
	int mid = (l + r) / 2;

	if(check(mid)) 
	    l = mid;
	else
	    r = mid;
    }

    printf("%d %lld\n", l, minAns);

    return 0;
}
