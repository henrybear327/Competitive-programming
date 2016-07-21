#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char inp[10000];
    while(fgets(inp, 10000, stdin) != NULL) {
	sscanf(inp, "%d", &n);
	if(n == 0)
	    break;

	fgets(inp, 10000, stdin);
	map<int, int> cnt;
	int len = strlen(inp);

	int who = -1, where = -1, vote = 0;
	for(int i = 0; i < len; i++) {
	    if('A' <= inp[i] && inp[i] <= 'Z') {
		vote++;
		cnt[inp[i] - 'A']++;

		auto it = cnt.rbegin();
		if(it->second > n / 2) {
		    who = it->first;
		    where = vote;
		    break;
		} else {
		    if((int)cnt.size() == 1)
			continue;
		   
		    vector< pair<int, int> > ss;
		    for(auto k : cnt) {
			ss.push_back(make_pair(k.second, k.first));
		    }
		    sort(ss.begin(), ss.end());
		    
		    int sss = ss.size();
		    if(ss[sss - 1].first == ss[sss - 2].first)
			continue;
		    if(ss[sss - 1].first > ss[sss - 2].first + (n - vote)) {
			who = ss[sss - 1].second;
			where = vote;
			break;
		    }
		}
	    }
	}

	if(who == -1) {
	    printf("TIE\n");
	} else {
	    printf("%c %d\n", who + 'A', where);
	}

    }

    return 0;
}
