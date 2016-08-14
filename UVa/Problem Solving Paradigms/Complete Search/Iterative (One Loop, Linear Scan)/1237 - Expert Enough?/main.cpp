#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> ii;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);
		
		pair<string, ii> db[11111];
		for(int i = 0; i < n; i++) {
			char inp[100];
			int l, h;
			
			scanf("%s %d %d", inp, &l, &h);

			db[i].x = inp;
			db[i].y.x = l;
			db[i].y.y = h;
		}
		
		int q;
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			int p;
			scanf("%d", &p);
			
			int idx, cnt = 0;
			for(int j = 0; j < n; j++) {
				if(db[j].y.x <= p && p <= db[j].y.y) {
					cnt++;
					idx = j;
				}
			}
			
			if(cnt == 1)
				printf("%s\n", db[idx].x.c_str());
			else
				printf("UNDETERMINED\n");
		}
		if(ncase != 0)
			printf("\n");
	}

	return 0;
}
