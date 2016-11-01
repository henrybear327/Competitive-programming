#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector< pair<int, char> > ans; 

bool check(vector<int> num, int offset)
{
	// printf("%d\n", offset);
	/*
	   for(int i = 0; i < (int)num.size(); i++) {
	   printf("%d: %d\n", i, num[i]);
	   }
	 */
	if((int)num.size() == 1)
		return true;

	int mx = 0;
	for(int i = 0; i < (int)num.size(); i++) 
		mx = max(mx, num[i]);
	
	for(int i = 0; i < (int)num.size(); i++) {
		if(num[i] == mx) {
			if(i - 1 >= 0 && num[i - 1] < mx) {
				int l = i;
				l = l < 0 ? 0 : l;
				int r = (int)num.size() - 1 - i;
				r = r < 0 ? 0 : r;

				// printf("%d %d\n", l, r);
				int pos = i;
				for(int j = 0; j < l; j++) {
					//printf("%d L\n", offset + pos--);
					ans.push_back(make_pair(offset + pos--, 'L'));
				}
				for(int j = 0; j < r; j++) {
					// printf("%d R\n", offset);
					ans.push_back(make_pair(offset, 'R'));
				}

				return true;
			} else if(i + 1 < (int)num.size() && num[i + 1] < mx)  {
				int l = i;
				l = l < 0 ? 0 : l;
				int r = (int)num.size() - 1 - i;
				r = r < 0 ? 0 : r;

				// printf("%d %d\n", l, r);
				int pos = i;
				for(int j = 0; j < r; j++) {
					//printf("%d R\n", offset);
					ans.push_back(make_pair(offset + i, 'R'));
				}
				for(int j = 0; j < l; j++) {
					//printf("%d L\n", offset + pos--);
					ans.push_back(make_pair(offset + pos--, 'L'));
				}

				return true;

			}
		}
	}

	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int inp[n + 1];
	for(int i = 1; i <= n; i++) 
		scanf("%d", &inp[i]);

	int prefix[n + 1];
	prefix[0] = 0;
	for(int i = 1; i <= n; i++)
		prefix[i] = prefix[i - 1] + inp[i];

	int m;
	scanf("%d", &m);
	int end[m + 1];
	for(int i = 1; i <= m; i++) 
		scanf("%d", &end[i]);

	vector<int> num;
	int prev = 0, idx = 1;
	bool error = false;
	for(int i = 1; i <= n + 1; i++) {
		// printf("%d %d\n", i, prev);
		if(prefix[i] - prefix[prev] <= end[idx] && i != n + 1) {
			num.push_back(inp[i]);
		} else {
			if(prefix[i - 1] - prefix[prev] != end[idx]) {
				error = true;
				break;
			}

			if(check(num, idx) == false) {
				error = true;
				break;
			}
			prev = i - 1;
			num.clear();
			idx++;
			num.push_back(inp[i]);
		}
	}

	if(idx - 1 == m && error == false) {
		printf("YES\n");
		for(auto i : ans)
			printf("%d %c\n", i.first, i.second);
		
	} else {
		printf("NO\n");
	}

	return 0;
}
