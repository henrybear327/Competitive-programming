#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);

	vector< queue<int> > que (n + 1);
	bool usedPos[q];
	queue< ii > query;
	memset(usedPos, false, sizeof(usedPos));

	int unread = 0, readSoFar = 0;
	for(int i = 0; i < q; i++) {
		int type, x;
		scanf("%d %d", &type, &x);

		if(type == 1) {
			unread++;
			que[x].push(i);
			query.push( ii(x, i) );
		} else if(type == 2) {
			while(que[x].empty() == false) {
				usedPos[que[x].front()] = true;
				que[x].pop();
				unread--;
			}
		} else {
			if(x > readSoFar) {
				while(x != readSoFar) {
					ii f = query.front();
					query.pop();
					
					readSoFar++;
					if(usedPos[f.second] == true) {
						continue;
					}
					unread--;
					que[f.first].pop();
				}
			}
		}

		printf("%d\n", unread);
	}

	return 0;
}
