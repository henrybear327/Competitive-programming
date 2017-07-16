// http://codeforces.com/problemset/problem/339/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	char inp[111];
	scanf("%s", inp);

	char* tok = strtok(inp, "+");
	vector<int> num;
	while(tok != NULL) {
		num.push_back(atoi(tok));

		tok = strtok(NULL, "+");
	}

	sort(num.begin(), num.end());
	
	int sz = num.size();
	for(int i = 0; i < sz; i++) 
		printf("%d%c", num[i], "+\n"[i == sz - 1]);

	return 0;
}
