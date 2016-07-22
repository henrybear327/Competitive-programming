#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 100000
bool p[N];
vector<int> pp;

void init()
{
    fill(p, p + N, true);
    p[0] = p[1] = false;

    for(ll i = 2; i < N; i++) {
	if(p[i] == false)
	    continue;
	pp.push_back(i);
	for(ll j = i * i; j < N; j += i) {
	    p[j] = false;
	}
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    init();
    
    ll ans = 0;
    while(n != 1) {
	int i; // watch out for LARGE prime (stuck in inf. loop is prime is greater than N!!)
	for(i = 0; i < (int)pp.size(); i++) {
	    if(n % pp[i] == 0) {
		ans += n;
		n /= pp[i];
		break;
	    }
	}
	if(i == (int)pp.size()) {
	    ans += n;
	    n /= n;
	}
    }

    printf("%lld\n", ans + 1);

    return 0;
}
