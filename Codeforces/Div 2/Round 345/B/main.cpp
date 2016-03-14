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
    
    int cnt[1010] = {0};
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);

	cnt[tmp]++;
    }
    
    vector<int> ans;
    while(n > 0) {
	for(int i = 1; i <= 1000; i++) {
	    if(cnt[i] != 0) {
		cnt[i]--;
		n--;
		ans.push_back(i);
	    }
	}
    }
    
    int res = 0;
    for(int i = 1; i < (int)ans.size(); i++) {
	if(ans[i] > ans[i - 1])
	    res++;
    }

    printf("%d\n", res);

    return 0;
}
