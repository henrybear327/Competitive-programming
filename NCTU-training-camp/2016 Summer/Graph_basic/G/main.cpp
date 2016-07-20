#include <bits/stdc++.h>

using namespace std;

vector<int> g[27];
vector<int> ans;

bool loop, seen[27], inAns[26], istack[26];
void dfs(int u)
{
    if(seen[u])
	return;
    seen[u] = true;
    istack[u] = true;

    for(auto v : g[u]) {
	if(istack[v]) {
	    loop = true;
	    break;
	}
	dfs(v);
    }
    if(u != 26 && inAns[u] == false) {
	ans.push_back(u);
	inAns[u] = true;
    }

    istack[u] = false;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    char prev[1000];

    bool error = false;
    scanf("%s", prev);
    int indeg[26] = {0}, used[26] = {0}, hasGraph = 0;
    for(int i = 0; i < n - 1; i++) {
	char cur[1000];
	scanf("%s", cur);
	
	int lenc = strlen(cur);
	int lenp = strlen(prev);

	int diff = -1;
	for(int j = 0; j < min(lenc, lenp); j++) {
	    if(prev[j] != cur[j]) {
		diff = j;
		break;
	    }
	}

	
	if(diff == -1 && lenc < lenp) {
	    error = true;
	    break;
	}
	
	if(diff == -1) {
	    strcpy(prev, cur);
	    continue;
	} 
	
	int from = prev[diff] - 'a', to = cur[diff] - 'a';
	g[from].push_back(to);
	
	used[from] = used[to] = 1;
	indeg[to]++;
	hasGraph = 1;
	//printf("%c %c\n", from + 'a', to + 'a');

	strcpy(prev, cur);
    }
   
    for(int i = 0; i < 26; i++) {
	if(indeg[i] == 0 && used[i] == 1) {
	    g[26].push_back(i);
	}
    }
    
    loop = false;
    memset(seen, false, sizeof(seen));
    memset(inAns, false, sizeof(inAns));
    dfs(26);
    
    /*
    for(int i = 0; i < (int)ans.size(); i++)
	printf("%c", ans[i] + 'a');
    printf("\n");
    */
    
    if(error == true)
	printf("Impossible\n");
    else if(hasGraph == 1 && ( loop == true || (int)ans.size() == 0) )
	printf("Impossible\n");
    else {
	for(int i = 0; i < 26; i++)
	    if(inAns[i] == false && used[i] == 1) {
		printf("Impossible\n");
		return 0;
	    }
	reverse(ans.begin(), ans.end());
	bool exist[26] = {false};
	for(int i = 0; i < (int)ans.size(); i++) {
	    printf("%c", ans[i] + 'a');
	    exist[ans[i]] = true;
	}

	for(int i = 0; i < 26; i++)
	    if(exist[i] == false)
		printf("%c", i + 'a');
    }

    return 0;
}
