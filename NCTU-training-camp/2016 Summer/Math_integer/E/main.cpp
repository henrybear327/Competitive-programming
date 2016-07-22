#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    // 21 35
    int a, b;
    scanf("%d %d", &a, &b);

    int g = gcd(a, b);
    a /= g;
    b /= g;

    int ca[3] = {0}, cb[3] = {0};
    if(a == b) {
	printf("0\n");
    } else {
	bool error = false;
	const int p[3] = {2, 3, 5};
	for(int i = 0; i < 3; i++) {
	    while(a != 1) {
		if(a % p[i] == 0) {
		    ca[i]++;
		    a /= p[i];
		} else 
		    break;
	    }
	}
	if(a != 1)
	    error = true;

	for(int i = 0; i < 3; i++) {
	    while(b != 1) {
		if(b % p[i] == 0) {
		    cb[i]++;
		    b /= p[i];
		} else 
		    break;
	    }
	}
	if(b != 1)
	    error = true;
	
	if(error)
	    printf("-1\n");
	else {
	    int ans = 0;
	    for(int i = 0; i < 3; i++)
		if(ca[i] != cb[i])
		    ans += abs(ca[i] - cb[i]);
	    printf("%d\n", ans);
	}
    }

    return 0;
}
