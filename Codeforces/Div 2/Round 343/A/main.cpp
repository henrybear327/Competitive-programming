#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int n;
int inp[100][100];

int main()
{
    scanf("%d", &n);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
	char tmp[n + 10];
	scanf("%s", tmp);
    
	int cnt = 0;
	for(int j = 0; j < n; j++) {
	    inp[i][j] = tmp[j] == '.' ? 0 : 1;    
	    cnt += inp[i][j];
	}

	ans += cnt  * (cnt - 1)/ 2;
    }
    
    //column
    for(int i = 0; i < n; i++) {
	int cnt = 0;
	for(int j = 0; j < n; j++) {
	    cnt += inp[j][i];	    
	}
	ans += cnt * (cnt - 1) / 2;
    }
	    
    printf("%d\n", ans);

    return 0;
}
