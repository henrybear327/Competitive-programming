#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int cnt[4];
	for(int i = 0; i < 4; i++)
		scanf("%d", &cnt[i]);
	
	// 2 3 5 6
	int a = 0, b = 0;
	while(cnt[0] > 0 && cnt[2] > 0 && cnt[3] > 0) {
		a++;
		cnt[0]--;
		cnt[2]--;
		cnt[3]--;
	}

	while(cnt[0] > 0 && cnt[1] > 0) {
		b++;
		cnt[0]--;
		cnt[1]--;
	}

	printf("%d\n", a * 256 + b * 32);
	
    return 0;
}
