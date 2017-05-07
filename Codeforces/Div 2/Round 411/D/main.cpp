#include <bits/stdc++.h>

using namespace std;

int main(){
	char inp[1111111];
	scanf("%s", inp);

	int len = strlen(inp);
	long long mod = (1e9) + 7, cnt = 0, base = 1;
	for(int i = 0; i < len; i++) {
		if(inp[i] == 'a') {
			base *= 2;
			base %= mod;
		} else {
			cnt += base;
			cnt--;
			cnt += mod;
			cnt %= mod;
		}
	}
	printf("%lld\n", cnt);
}
