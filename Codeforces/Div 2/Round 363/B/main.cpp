#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector<int> cnt[1111];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    bool hasBomb = false;
    for(int i = 0; i < n; i++) {
	char inp[10000];
	scanf("%s", inp);
	for(int j = 0; j < m; j++) {
	    if(inp[j] == '*') {
		cnt[j].push_back(i);
		hasBomb = true;
	    }
	}
    }

    if(hasBomb == false) {
	printf("YES\n");
	printf("1 1\n");
	return 0;
    }

    int mxrow, mx = -1;
    for(int i = 0; i < m; i++) {
	if((int)cnt[i].size() > mx) {
	    mx = (int)cnt[i].size();
	    mxrow = i;
	}
    }

    bool error = false;
    int ansx, ansy;
    if(mx < 2) {
	// only row has bomb
	int val = -1, yy;
	for(int i = 0; i < m; i++) {
	    if((int)cnt[i].size() != 0) {
		if(val == -1) {
		    val = cnt[i][0];
		    yy = i;
		} else {
		    if(val != cnt[i][0])
			error = true;
		}
	    }
	}

	if(error == false) {
	    ansx = val;
	    ansy = yy;
	}
    } else {
	int val = -1; // val = x
	for(int i = 0; i < m; i++) {
	    if(i == mxrow)
		continue;
	    if((int)cnt[i].size() > 1) {
		error = true;
		break;
	    }

	    if((int)cnt[i].size() == 0)
		continue;
	    if(val == -1)
		val = cnt[i][0];
	    else {
		if(val != cnt[i][0]) {
		    error = true;
		    break;
		}
	    }
	}

	if(error == false) {
	    ansx = val == -1 ? 0 : val;
	    ansy = mxrow;
	}
    }

    if(error == false) {
	printf("YES\n");
	printf("%d %d\n", ansx + 1, ansy + 1);
    } else {
	printf("NO\n");
    }

    return 0;
}
