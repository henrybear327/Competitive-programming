#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#define INF ((int)1e6+10)
int main()
{
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);

    // get input and accumulate by column
    int cnt[2][m + 1]; // [0] = #, [1] = .
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
	char inp[1010];
	scanf("%s", inp);
	for(int j = 0; j < m; j++) {
	    if(inp[j] == '#')
		cnt[0][j + 1]++;
	    else
		cnt[1][j + 1]++;
	}
    }
    
#if DEBUG == 1
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", cnt[0][i], i == m ? '\n' : ' ');
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", cnt[1][i], i == m ? '\n' : ' ');
#endif

    // get prefix for accumulated list
    int prefix[2][m + 1];
    prefix[0][0] = prefix[1][0] = 0;
    for(int i = 1; i < m + 1; i++) {
	prefix[0][i] = prefix[0][i - 1] + cnt[0][i];
	prefix[1][i] = prefix[1][i - 1] + cnt[1][i];
    }
    
#if DEBUG == 1
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", prefix[0][i], i == m ? '\n' : ' ');
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", prefix[1][i], i == m ? '\n' : ' ');
#endif

    // get DP answer, just like spaceship from 581 programming exercise
    // but god knows why...
    int res[2][m + 1];
    for(int j = 0; j < m + 1; j++)
	res[0][j] = res[1][j] = INF;
    res[0][0] = res[1][0] = 0;
#if DEBUG == 1
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", res[0][i], i == m ? '\n' : ' ');
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", res[1][i], i == m ? '\n' : ' ');
#endif

    for(int i = 0; i < m; i++) {
	for(int j = x; j <= y && i + j < m + 1; j++) {
	    res[0][i + j] = min(res[0][i + j], res[1][i] + prefix[0][i + j] - prefix[0][i]);
	    res[1][i + j] = min(res[1][i + j], res[0][i] + prefix[1][i + j] - prefix[1][i]);
	}
    }

#if DEBUG == 1
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", res[0][i], i == m ? '\n' : ' ');
    for(int i = 0; i < m + 1; i++)
	printf("%d%c", res[1][i], i == m ? '\n' : ' ');
#endif

    printf("%d\n", min(res[0][m], res[1][m]));

    return 0;
}
