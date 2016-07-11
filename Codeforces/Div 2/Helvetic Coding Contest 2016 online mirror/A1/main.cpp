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
    
    int ans = 0;
    if(n % 2 == 1) {
	ans = 1 + (n - 1) / 2;
    } else {
	ans = n / 2;
    }
    printf("%d\n", ans);

    return 0;
}
