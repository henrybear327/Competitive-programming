#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long ll;
ll comb[64][64];

void cal_comb()
{
    // pre-cal comb 
    // init (n, 1) (n, n)
    for(int i = 1; i <= 63; i++) {
	comb[i][0] = 1;
	comb[i][1] = i;
	comb[i][i] = 1;
    }

    // cal
    for(int i = 3; i <= 63; i++) {
	for(int j = 2; j < i; j++) {
	    // (i, j)
	    comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}
    }
}

int main()
{
    cal_comb();

    int m, k;
    scanf("%d %d", &m, &k);

     

    return 0;
}
