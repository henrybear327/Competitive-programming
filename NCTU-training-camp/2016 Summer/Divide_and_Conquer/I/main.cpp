#include <cstdio>

typedef long long ll;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    for(int i = 0; i < n; i++) {
	int cur;
	scanf("%d", &cur);

	ll res = ((ll)cur * a) % b / a;
	// a = 7 b = 100, if we have 2 coins -> 2 * 7 % 100 = 14 -> more coins than initial state
	// thus, (cur * a) % b / a will yield the correct answer
	if(res == 0)
	    printf("%d ", 0);
	else
	    printf("%lld ", res);
    }

    return 0;
}
