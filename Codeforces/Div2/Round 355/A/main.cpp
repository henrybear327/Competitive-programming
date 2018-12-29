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
    int n, m;
    scanf("%d %d", &n, &m);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);
	ans += tmp > m ? 2 : 1;
    }
    printf("%d\n", ans);

    return 0;
}
