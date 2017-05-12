#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> inp;
	for(int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		inp.push_back(tmp);
	}

	sort(inp.begin(), inp.end());

	for(int i = 0; i < n; i++)
		printf("%d\n", inp[i]);

	return 0;
}
