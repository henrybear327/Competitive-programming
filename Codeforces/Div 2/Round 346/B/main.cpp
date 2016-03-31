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
    int n, m;
    scanf("%d %d", &n, &m);

    vector< pair<int, string> > inp[m + 1];
    for(int i = 0; i < n; i++) {
	char str[100];
	int reg, score;
	scanf("%s %d %d", str, &reg, &score);
	inp[reg].push_back(make_pair(score, str));
    }

    for(int i = 1; i <= m; i++) {
	sort(inp[i].begin(), inp[i].end());
    }
    /*
    for(int i = 1; i <= m; i++) {
	for(int j = 0; j < (int)inp[i].size(); j++) 
	    printf("%d %s,", inp[i][j].first, inp[i][j].second.c_str());
	printf("\n");
    }
    */

    for(int i = 1; i <= m; i++) {
	int last = inp[i].size() - 1;
	if(last > 1) {
	    if(inp[i][last].first == inp[i][last - 1].first
		    && inp[i][last - 1].first == inp[i][last - 2].first)
		printf("?\n");
	    else if(inp[i][last].first != inp[i][last - 1].first
		    && inp[i][last - 1].first == inp[i][last - 2].first)
		printf("?\n");
	    else {
		printf("%s %s\n", inp[i][last].second.c_str(), inp[i][last - 1].second.c_str());
	    }
	} else 
	    printf("%s %s\n", inp[i][last].second.c_str(), inp[i][last - 1].second.c_str());
    }

    return 0;
}
