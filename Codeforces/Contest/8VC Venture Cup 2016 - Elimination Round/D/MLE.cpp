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

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    sort(inp, inp + n);

    vector< pair<int, int> > init;
    for(int i = 0; i < n; i++)
	for(int j = i + 1; j < n; j++)
	    init.push_back(make_pair(inp[i], inp[j]));
    
    int ans = n * n * n,cnt = 0;
    for(auto out : init) {
	for(auto in : init) {
	    int f, b;
	    if(f = (in.first + out.first) < b = (in.second + out.second)) {
		cnt += (upper_bound(inp, inp + n, make_pair(a, b)) - inp);
	    }
	}
    }
    
    for(auto out : init) {
	for(auto in : round2) {
	    cnt++;
	    if(out.second + in.first > out.first + in.second)
		ans++;
	}
    }

    // printf("%d %d\n", ans, cnt);
    printf("%.15f\n", (double)ans / cnt);

    return 0;
}
