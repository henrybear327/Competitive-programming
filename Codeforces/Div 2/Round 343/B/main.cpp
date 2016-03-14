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
    pair<int, int> cnt[367];

    for(int i = 0; i < n; i++) {
	char gen[10];
	int a, b;
	scanf("%s %d %d", gen, &a, &b);
	b++;

	if(gen[0] == 'M') {
	    for(int i = a; i < b; i++)
		cnt[i].first++;
	} else {
	    for(int i = a; i < b; i++)
		cnt[i].second++;
	}
    }
    
    int ans = INT_MIN;
    for(int i = 1; i <= 366; i++) {
	ans = max(ans, min(cnt[i].first, cnt[i].second) * 2);
    }	

    printf("%d\n", ans);

    return 0;
}
