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

    int val[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &val[i]);
    
    ll suma = 0, sumb = 0;
    char str[n + 10];
    scanf("%s", str);
    for(int i = 0; i < n; i++) {
	if(str[i] == 'A')
	    suma += val[i];
	else
	    sumb += val[i];
    }
    
    ll ans = sumb;
    ll origa = suma, origb = sumb;
    //prefix
    for(int i = 0; i < n; i++) {
	if(str[i] == 'A') {
	    suma -= val[i];
	    sumb += val[i];
	} else {
	    suma += val[i];
	    sumb -= val[i];
	}
	ans = max(ans, sumb);
    }

    //suffix
    suma = origa;
    sumb = origb;
    for(int i = n - 1; i >= 0; i--) {
	if(str[i] == 'A') {
	    suma -= val[i];
	    sumb += val[i];
	} else {
	    suma += val[i];
	    sumb -= val[i];
	}
	ans = max(ans, sumb);
    }

    printf("%lld\n", ans);

    return 0;
}
