#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int cnt[110] = {0};
    int sum = 0;
    for(int i = 0; i < 5; i++) {
	int tmp;
	scanf("%d", &tmp);

	cnt[tmp]++;
	sum += tmp;
    }
    
    int ans = sum;
    for(int i = 0; i < 110; i++) {
	if(cnt[i] >= 2) {
	    ans = min(ans, sum - i * (cnt[i] > 3 ? 3 : cnt[i]));
	}
    }
    printf("%d\n", ans);
    
    return 0;
}
