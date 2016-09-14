#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	set<int> s;
	vector<int> num;
	for(int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);
		
		if(s.find(cur) == s.end()) {
			s.insert(cur);
			num.push_back(cur);
		}
	}
		
	sort(num.begin(), num.end());
	bool ok = false;
	if(s.size() == 1)
		ok = true;
	else if(s.size() == 2) {
		ok = true;
	} else if(s.size() == 3) {
		if(num[1] - num[0] == num[2] - num[1])
			ok = true;
	} 

	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}
