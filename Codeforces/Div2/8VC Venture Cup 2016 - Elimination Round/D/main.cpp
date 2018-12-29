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
    ll n; //Crucial bug, be neat!
    scanf("%lld", &n);

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    // get all combination's diff cnt
    ll diff[5010] = {0};
    for(int i = 0; i < n; i++)
	for(int j = i + 1; j < n; j++)
	    diff[abs(inp[i] - inp[j])]++;

    ll prefix[5010] = {0}; // get the cnt prefix sum from the end
    for(int i = 5000; i >= 0; i--)
	prefix[i] = prefix[i + 1] + diff[i];

    ll ans = 0;
    for(int i = 0; i <= 5000; i++)
	for(int j = 0; j <= 5000; j++)
	    if(i + j + 1 <= 5000) // crucial bug!! Be neat!
		ans += diff[i] * diff[j] * prefix[i + j + 1];

    n = n * (n - 1) / 2;// c(n, 2)
    printf("%.15f\n", (double) ans / (n * n * n)); 

    return 0;
}
