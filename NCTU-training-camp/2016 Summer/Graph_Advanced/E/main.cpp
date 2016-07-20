#include <bits/stdc++.h>

using namespace std;

#define N 100010
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    
    int inp[n];
    map<int, int> g; // num, group
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
	g[inp[i]] = 0;
    }
    
    vector<int> move;
    for(auto i : g) {
	if(g.find(a - i.first) == g.end()) {
	    g[i.first] = 1;	    
	    move.push_back(i.first);
	}
    }
    
    bool ok = true;
    for(int i = 0; i < (int)move.size(); i++) {
	if(g.find(b - move[i]) == g.end()) {
	    ok = false;
	    break;
	} else if(g[b - move[i]] == 0) {
	    g[b - move[i]] = 1;

	    int check = a - (b - move[i]);
	    g[check] = 1; // the original number of a - (b - i) should also come to group 2, this will be a cascading effect
	    move.push_back(check);
	}
    }
    
    if(ok) {
	printf("YES\n");
	for(int i = 0; i < n; i++)
	    printf("%d ", g[inp[i]]);
    } else {
	printf("NO\n");
    }

    return 0;
}
