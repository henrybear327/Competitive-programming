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
    int n, dist;
    scanf("%d %d", &n, &dist);

    char inp[n + 10];
    scanf("%s", inp);

    vector<char> ans;
    for(int i = 0; i < n; i++) {
	int diffz = inp[i] + dist > 'z' ? 'z' - inp[i] : dist;
	int diffa = inp[i] - dist < 'a' ? inp[i] - 'a' : dist;
	
	if(dist == 0)
	    ans.push_back(inp[i]);
	else if(diffz > diffa) {
	    dist -= diffz;
	    ans.push_back(inp[i] + diffz);
	} else {
	    dist -= diffa;
	    ans.push_back(inp[i] - diffa);
	}
    }
    
    if(dist != 0)
	printf("-1\n");
    else
	for(int i = 0; i < n; i++)
	    printf("%c", ans[i]);

    return 0;
}
