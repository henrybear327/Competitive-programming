#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<char, int>&a, const pair<char, int> &b)
{
    if(a.second == b.second)
	return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    char inp[10010];
    bool fst = true;
    while(fgets(inp, 10010, stdin) != NULL) {
	if(fst == true)
	    fst = !fst;
	else
	    printf("\n");

	map<char, int> cnt;
	for(int i = 0; inp[i] != '\0'; i++) {
	    if(inp[i] == '\r' || inp[i] == '\n')
		continue;
	    cnt[inp[i]]++;
	}

	vector< pair<char, int> > ans;
	for(auto i : cnt) {
	    ans.push_back(make_pair(i.first, i.second));
	}

	sort(ans.begin(), ans.end(), cmp);
	
	for(auto i : ans)
	    printf("%d %d\n", (int)i.first, i.second);
    }

    return 0;
}
