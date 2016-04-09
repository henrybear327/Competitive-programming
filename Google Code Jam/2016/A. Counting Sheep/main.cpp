#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll check(ll n)
{
    bool ok[10] = {false};
    int cnt = 0;
    ll ret = 0;
    for(ll i = 1; cnt < 10; i++) {
	ll tmp = n * i;
	ret = tmp;
	while(tmp) {
	    if(ok[tmp % 10] == false) {
		ok[tmp % 10] = true;
		cnt++;
	    }
	    tmp /= 10;
	}
    }

    return ret;
}

int main()
{
    int ncase, case_cnt = 1;
    /*
    for(int i = 0; i <= 1000000; i++) { 
	int n = i;
	if(n == 0)
	    printf("%d Case #%d: INSOMNIA\n", n, case_cnt);
	else
	    printf("%d Case #%d: %lld\n", n, case_cnt, check(n));

	case_cnt++;
    }
    */

    scanf("%d", &ncase);

    while(ncase--) {
	int n;
	scanf("%d", &n);

	if(n == 0)
	    printf("Case #%d: INSOMNIA\n", case_cnt);
	else
	    printf("Case #%d: %lld\n", case_cnt, check(n));

	case_cnt++;
    }

    return 0;
}
