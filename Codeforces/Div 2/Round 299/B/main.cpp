#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);

	ll encode = 0, cnt = 0;
	while(n) {
		if(n % 10 == 7) {
			encode |= (1 << cnt);
		}
		n /= 10;
		cnt++;
	}
	
	ll prev = 1, cur = 2;
	ll power = 2;
	for(int i = 1; ; i++) {
		if(i == cnt)
			break;
		power *= 2;
		prev = cur + 1;
		cur += power;
	}
	
	printf("%lld\n", prev + encode);
    return 0;
}
