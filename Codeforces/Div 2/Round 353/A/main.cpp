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
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(c == 0 && b == a)
	printf("YES\n");
    else if(c != 0 && (b - a) % c == 0 && (b - a) / c >= 0)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
