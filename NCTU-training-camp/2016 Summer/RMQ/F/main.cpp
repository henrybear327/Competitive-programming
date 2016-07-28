#include <bits/stdc++.h>

using namespace std;

#define N 1000010
typedef pair<int, int> ii;
int main()
{
	char inp[N];
	scanf("%s", inp);

	int n;
	scanf("%d", &n);

	map< int, set< ii > > q;
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		
		q[a].insert(ii(b, i));
	}
	
	int ans[n];
	for(auto i : q) {
		stack< ii > s;
		int idx = 0, sum = 0;
		for(ii j : i.second) {
			int pos = j.first;
			
			while(idx <= pos) {
				if(inp[idx] == '(')
					s.push(ii(inp[idx], idx));
				else {
					if(s.empty() == false && s.top().first == '(') {
						if(s.top().second >= i.first)
							sum += 2;
						s.pop();
					}	
				}
				if(idx == i.first)
					sum = 0;
				idx++;
			}

			ans[j.second] = sum;
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}
