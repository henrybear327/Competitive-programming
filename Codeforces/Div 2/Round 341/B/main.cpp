#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int m[1010][1010];
    memset(m, 0, sizeof(m));
    
    map<int, int> s1, s2;
    for(int i = 0; i < n; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	s1[b - a]++;
	s2[b + a]++;
    }
	
    long long int ans = 0;

    for(auto i : s1) {
	int tmp = i.second;
	ans += tmp * (tmp - 1) / 2;
    }

    for(auto i : s2) {
	int tmp = i.second;
	ans += tmp * (tmp - 1) / 2;
    }
    
    printf("%lld\n", ans); 

    return 0;
}
