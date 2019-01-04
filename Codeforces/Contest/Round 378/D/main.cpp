#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	map< ii, set<ii> > data;
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		// ab
		int l = min(a, b);
		int r = max(a, b);
		data[ii(l, r)].insert(ii(c, i));	

		// ac
		l = min(a, c);
		r = max(a, c);
		data[ii(l, r)].insert(ii(b, i));	

		// bc
		l = min(b, c);
		r = max(b, c);
		data[ii(l, r)].insert(ii(a, i));	
	}
	
	int minimax = -1;
	int idx1 = -1, idx2 = -1;
	for(auto i : data) {
		if(i.second.size() == 1) {
			auto it = i.second.begin();
			int mx = min(min(i.first.first, i.first.second), it->first);
			if(mx > minimax) {
				minimax = mx;
				idx1 = it->second;
				idx2 = -1;
			}
		} else {
			auto it0 = i.second.rbegin();
			auto it1 = i.second.rbegin();
			it1++;

			int mx = min(min(i.first.first, i.first.second), it0->first + it1->first);
			if(mx > minimax) {
				minimax = mx;
				idx1 = it0->second;
				idx2 = it1->second;
			}
		}
	}

	if(idx2 == -1)
		printf("1\n%d\n", idx1);
	else
		printf("2\n%d %d\n", idx1, idx2);
	
    return 0;
}
