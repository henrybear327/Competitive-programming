#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int k = 0;
	while( (1 << (k + 1)) <= m ) {
		k++;
	}

	if(n > k) {
		printf("%d\n", m);
	} else {
		printf("%d\n", m % (1 << n));
	}	
	
    return 0;
}
