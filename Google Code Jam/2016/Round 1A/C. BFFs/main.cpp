#include <bits/stdc++.h>

using namespace std;

int inp[1010], ans, maxLen[1010];
void getMaxLen(int i)
{
    set<int> s;
    s.insert(i);
    while(s.find(inp[i]) == s.end()) {
	s.insert(inp[i]);
	i = inp[i];
    }

    // i will be the entry point for the path to the cycle

    // get the length of the cycle
    int len = 1;
    for(int next = inp[i]; next != i; next = inp[next])
	len++;
    
    if(len == 2) {
	maxLen[i] = max(maxLen[i], (int)s.size() - 2); // the longest incoming path from this node on the cycle 

	ans = max(ans, 2 + maxLen[i] + maxLen[inp[i]]);
    } else {
	ans = max(ans, len);
    }
}

int main()
{
    /* 
    curcial observation

    If a cycle with length > 2, then there is no way to have others come in to sit with them.
    If there is a cycle with length == 2, then only one longest path pointing in can be added
    */
    int ncase;
    scanf("%d", &ncase);
    
    for(int ccc = 1; ccc <= ncase; ccc++) {
	ans = 0;
	memset(maxLen, 0, sizeof(maxLen));

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	    scanf("%d", &inp[i]);
	
	for(int i = 1; i <= n; i++) {
	    getMaxLen(i);
	}
	
	printf("Case #%d: %d\n", ccc, ans);
    }

    return 0;
}
