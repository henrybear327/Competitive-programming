#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
	char inp[1000];
	inp[0] = '(';
	scanf("%s", inp + 1);
	int len = strlen(inp);
	inp[len] = ')';
	len++;
	inp[len] = '\0';
	// printf("%s\n", inp);

	stack<string> s;
	for(int i = 0; i < len; i++) {
		string c = string(1, inp[i]);
		if(c == ")") {
			while(s.size() >= 3) {
				string two = s.top();
				s.pop();
				string sign = s.top();
				s.pop();
				string one = s.top();
				s.pop();

				string in = one + two + sign;
				// printf("in %s\n", in.c_str());
				if(s.top() == "(") {
					s.pop();
					s.push(in);
					break;
				}
				s.push(in);
			}
		} else {
			s.push(c);
		}
	}
	
	printf("%s\n", s.top().c_str());
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
