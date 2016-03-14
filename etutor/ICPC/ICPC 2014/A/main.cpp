#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	int ver, hor, line;
	scanf("%d %d %d", &ver, &line, &hor);

	vector< pair<int, int> > inp[ver];

	for(int i = 0; i < line; i++) {
	    int a, b;
	    scanf("%d %d", &a, &b);

	    inp[a].push_back(make_pair(b, 1));
	    inp[a + 1].push_back(make_pair(b, -1));
	}	

	for(int i = 0; i < ver; i++) {
	    sort(inp[i].begin(), inp[i].end());
	}
	
	/*
	for(int i = 0; i < ver; i++) {
	    printf("%d: ", i);
	    for(int j = 0; j < (int)inp[i].size(); j++) {
		printf("%d %d, ", inp[i][j].first, inp[i][j].second);
	    }
	    printf("\n");
	}
	*/

	for(int i = 0; i < ver; i++) {
	    int pos = i, max_hor = 0;
	    bool flag = true;
	    while(flag) {
		for(int j = 0; j <= (int)inp[pos].size(); j++) {
		    if(j == (int)inp[pos].size()) {
			flag= false;
			break;
		    }

		    if(inp[pos][j].first > max_hor) {
			max_hor = inp[pos][j].first;
			pos += inp[pos][j].second;
			j = -1;
		    }
		}
	    }

	    printf("%d\n", pos);
	}
    }

    return 0;
}
