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
    int n;
    scanf("%d", &n);

    if(n > 26) {
	printf("-1\n");
	return 0;
    }
    
    char inp[n + 2];
    scanf("%s", inp);

    int cnt[26] = {0};
    for(int i = 0; i < n; i++)
	cnt[inp[i] - 'a']++;
    
    int diff = 0;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
	if(cnt[i] != 0) {
	    diff++;
	    ans += cnt[i] - 1;
	}
    }

    printf("%d\n", ans);

    return 0;
}
