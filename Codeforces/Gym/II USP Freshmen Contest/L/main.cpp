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
    int n;
    scanf("%d", &n);
    
    vector< pair<int, int> > inp;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);

	inp.push_back(make_pair(tmp, i + 1));
    }

    sort(inp.begin(), inp.end());

    if(n > 1 && inp[n - 1].first == inp[n - 2].first)
	printf("-1\n");
    else
	printf("%d\n", inp[n - 1].second);

    return 0;
}
