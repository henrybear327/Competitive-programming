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
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    // use two pointers to solve
    int l = 0, r = 0; // [l, r) Using this bound will be easy to control! When l == r, r will always increment!
    int ansl = 0, ansr = 0;
    int cnt = 0;
    while(l < n) {
	// let r go as far as it can, and stop at the right most point that is conflicting with the condition given -> [l, r)
	while(r < n && cnt <= k) { // cnt == k! Or the consecutive 1s won't be treated as consecutive ones!
	    if(inp[r] == 0) {
		if(cnt == k) // deal with cnt == k here!
		    break;
		cnt++;
	    }
	    r++;
	}
	// update the range now, it'll be the largest range because r is further to the right where l is at the left-most pos
	if(r - l > ansr - ansl) {
	    ansr = r;
	    ansl = l;
	}
	
	// increment l by 1 per loop
	cnt -= (inp[l] == 0 ? 1 : 0); // if l is on a 0, then cnt-- -> [l, r)
	l++;
    }

    printf("%d\n", ansr - ansl);
    for(int i = 0; i < n; i++)
	if(ansl <= i && i < ansr)
	    printf("1 ");
	else
	    printf("%d ", inp[i]);
    printf("\n");

    return 0;
}
