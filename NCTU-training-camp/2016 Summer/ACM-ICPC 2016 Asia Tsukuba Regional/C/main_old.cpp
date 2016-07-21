#include <bits/stdc++.h>

using namespace std;

#define N 8000000
typedef pair< bool, int > ii;
ii ok[N];

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2 && (n || m)) {
	fill(ok, ok + N, ii(false, 0));

	int idx = m;
	while(n > 0) {
	    if(ok[idx].first == false) {
		ok[idx].first = true;
		ok[idx].second = idx;

		ok[idx * 2].first = true;
		ok[idx * 2].second = idx;

		n--;
	    } else {
		int prev = ok[idx].second;
		ok[idx + prev].first = true;
		ok[idx + prev].second = prev;
	    }

	    idx++;
	}
	
	for(int i = 0; i < 100; i++) {
	    printf("%d %d %d\n", i, ok[i].first, ok[i].second);
	}
	    
	for(int i = idx - 1; i < N; i++) {
	    if(ok[i].first == false) {
		printf("%d\n", i);
		break;
	    }
	}
    }

    return 0;
}
