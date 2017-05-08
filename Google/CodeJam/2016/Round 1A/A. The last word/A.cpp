#include <bits/stdc++.h>

using namespace std;
int main()
{
    int ncase;
    scanf("%d", &ncase);

    for(int i = 1; i <= ncase; i++) {
	string inp;
	cin >> inp;

	deque<char> ans;
	ans.push_back(inp[0]);
	for(int j = 1; j < inp.length(); j++) {
	    if(inp[j] >= ans.front())
		ans.push_front(inp[j]);
	    else
		ans.push_back(inp[j]);
	}
	
	printf("Case #%d: ", i);
	while(ans.empty() == false) {
	    printf("%c", ans.front());
	    ans.pop_front();
	}
	printf("\n");
    }

    return 0;
}
