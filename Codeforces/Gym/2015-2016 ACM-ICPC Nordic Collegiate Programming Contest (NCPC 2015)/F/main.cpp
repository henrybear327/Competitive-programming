#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f;
    scanf("%d", &f);

    bool all_ok = true;
    for(int i = 0; i < f && all_ok
	/*bitch this caused me 1 hour, early termination not done properly will cause next a, b value incorrect!*/
	; i++) {
	int t, n;
	scanf("%d %d", &t, &n);

	bool possible[2][10010];
	fill(possible[0], possible[0] + t + 1, true);
	for(int j = 0; j < n; j++) {
	    fill(possible[(j & 1) ^ 1], possible[(j & 1) ^ 1] + t + 1, false);

	    int a, b;
	    scanf("%d %d", &a, &b);
	    for(int k = 0; k <= t; k++) {
		if(possible[j & 1][k] == false)
		    continue;
		if(k - (b - a) >= 0) {
		    possible[(j & 1) ^ 1][k - (b - a)] = true;
		}
		if(k + (b - a) <= t) {
		    possible[(j & 1) ^ 1][k + (b - a)] = true;
		}
	    }
	    
	    bool ok = false;
	    for(int k = 0; k <= t; k++) 
		if(possible[(j & 1) ^ 1][k] == true) {
		    ok = true;
		    break;
		}
	    if(ok == false) {
		all_ok = false;
		break;
	    }
	}
    }

    if(all_ok == true)
	printf("possible\n");
    else
	printf("impossible\n");

    return 0;
}
