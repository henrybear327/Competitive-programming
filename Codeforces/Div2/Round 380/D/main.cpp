#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, a, b, k;
	scanf("%d %d %d %d", &n, &a, &b, &k);
	
	char inp[n + 10];
	inp[0] = '1';
	scanf("%s", inp + 1);
	inp[n + 1] = '1';
	// printf("%s\n", inp);

	priority_queue<ii> pq;
	int can = 0, prev = 0;
	for(int i = 0; i < n + 2; i++) {
		if(inp[i] == '1') {
			if(i - prev  - 1 > 0) {
				pq.push(ii(i - prev - 1, prev + 1));
				can += (i - prev - 1) / b;
			}
			prev = i;
		}
	}
	
	printf("%d\n", can - a + 1);
	can = a;
	int firstLoc = -1;
	while(pq.empty() == false) {
		ii cur = pq.top();
		pq.pop();
		// printf("oo %d %d\n", cur.first, cur.second);

		int reduce = cur.first / b;
		// printf("rr %d %d\n", reduce, can);
		if(reduce > 0 && can > 0 && firstLoc == -1)
			firstLoc = cur.second + b - 1;

		if(reduce > can) {
			reduce = can;
			can = 0;
		} else
			can -= reduce;

		cur.first -= reduce * b;
		cur.second += reduce * b;
		// printf("cc %d %d\n", cur.first, cur.second);

		while(cur.first >= b) {
			printf("%d ", cur.second + b - 1);
			cur.second += b;
			cur.first -= b;
		}
	}
	printf("%d \n", firstLoc);

    return 0;
}
