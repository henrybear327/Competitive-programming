#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int seq[6] = {0, 1, 2, 3, 4, 5};
    
    int g[6][6];
    for(int i = 1; i <= 5; i++)
	for(int j = 1; j <= 5; j++)
	    scanf("%d", &g[i][j]);

    int ans = INT_MIN;
    do {	
	int tmp = 0;
	for(int i = 1; i <= 4; i++)  {
	    for(int j = i; j <= 4; j += 2) {
		tmp += g[seq[j]][seq[j + 1]] + g[seq[j + 1]][seq[j]];
	    }
	}
	ans = max(ans, tmp);
    } while(next_permutation(seq + 1, seq + 6) == true);

    printf("%d\n", ans);

    return 0;
}
