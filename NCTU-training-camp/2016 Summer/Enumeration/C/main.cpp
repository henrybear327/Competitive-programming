#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    vector<ii> r;
    for(int i = 1; i < n; i++) {
	int a = inp[i - 1];
	int b = inp[i];
	r.push_back(ii(min(a, b), max(a, b)));
    }

    
    bool ok = true;
    for(int i = 0; i < (int)r.size(); i++) {
	for(int j = i + 1; j < (int)r.size(); j++) {
	    int l1 = r[i].first;
	    int l2 = r[j].first;
	    int r1 = r[i].second;
	    int r2 = r[j].second;

	    if( (l1 < l2 && l2 < r1) && (r2 > r1) ) {
		//printf("%d %d %d %d\n", l1, r1, l2, r2);
		ok = false;
	    }
	    if( (l2 < l1) && (l1 < r2 && r2 < r1) ) {
		//printf("%d %d %d %d\n", l1, r1, l2, r2);
		ok = false;
	    }
	}
    }

    if(ok == false)
	printf("yes\n");
    else
	printf("no\n");

    return 0;
}
