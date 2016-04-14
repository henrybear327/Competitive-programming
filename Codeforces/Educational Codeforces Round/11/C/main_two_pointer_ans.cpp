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
    int ansl = 0, ansr = 0;
    int j = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
	if (j < i) { 
	    j = i;
	    cnt = 0;
	}

	while (j < n) { // right bound, exclusive, terminates at the index where cnt is about to increase over k
	    int ncnt = cnt + !inp[j];
	    if (ncnt > k) break;
	    cnt += !inp[j];
	    j++;
	}

	if (j - i > ansr - ansl) // the greatest interval
	    ansl = i, ansr = j;

	if (cnt > 0) cnt -= !inp[i]; // i will increase, so cnt must be adjusted accordingly
    }

    printf("%d\n", ansr - ansl);
    for(int i = ansl; i < ansr; i++)
	inp[i] = 1;
    for(int i = 0; i < n; i++) {
	if (i) putchar(' ');
	printf("%d", inp[i]);
    }
    puts("");

    return 0;
}
