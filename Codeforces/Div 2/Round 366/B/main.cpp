#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int turn = 1;
	for(int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);

		if(cur == 1) {
			printf("%d\n", turn == 1 ? 2 : 1); 
		} else {
			if( (cur - 1) % 2 == 1 )
				turn = turn == 1 ? 2 : 1;
			printf("%d\n", turn == 1 ? 2 : 1);
		}
	}
	
    return 0;
}
