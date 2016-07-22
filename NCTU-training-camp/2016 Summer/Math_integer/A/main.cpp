#include <bits/stdc++.h>

using namespace std;

#define N 1000100
bool prime[N];
void init()
{
    fill(prime, prime + N, true);
    
    prime[0] = prime[1] = false;
    for(long long i = 2; i < N; i++) {
	if(prime[i] == false)
	    continue;
	for(long long j = i * i; j < N; j += i) {
	    prime[j] = false;
	}
    }
}

int main()
{
    init();

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
	long long cur;
	scanf("%lld", &cur);
	long long cur2 = sqrt(cur);
	if(cur2 * cur2 != cur)
	    printf("NO\n");
	else
	    if(prime[cur2])
		printf("YES\n");
	    else
		printf("NO\n");
    }

    return 0;
}
