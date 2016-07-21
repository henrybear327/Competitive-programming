#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define N (ll)8000000
bool ok[N];

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2 && (n || m)) {
	memset(ok, false, sizeof(ok));
	
	ll i;
	for(i = m; n > 0 && i < N; i++) {
	    if(ok[i] == false) {
		n--;
		ok[i] = true;
		for(ll j = i * 2; j < N; j += i) {
		    ok[j] = true;
		}
	    }
	}   
	
	i--;
	for(; i < N; i++) {
	    if(ok[i] == false) {
		printf("%lld\n", i);
		break;
	    }	
	}
    }

    return 0;
}
