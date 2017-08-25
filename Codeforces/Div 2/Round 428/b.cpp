/*
1 4
2 2 2 2

2 7
2 2 2 2 2 2 2

2 8
2 2 2 2 2 2 2 1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

	int four = n;
	int two = n * 2;

	int cnt[3] = {0};
    for (int i = 0; i < k; i++) {
		int num;
        scanf("%d", &num);

        while(num >= 3) {
			if(four > 0) {
				four--;
				num -= min(4, num);
			} else if(two > 0) {
				two -= 2;
				num -= min(4, num);
			} else {
				puts("NO");
				return 0;
			}
		}

		cnt[num]++;
	}
	
	int one = 0;
	while(cnt[2] > 0) {
		if(four > 0) {
			four--;
			cnt[2]--;
			one++;
		} else if(two > 0) {
			two--;
			cnt[2]--;
		} else {
			cnt[1] += cnt[2] * 2;
			cnt[2] = 0;
		}
	}

	while(cnt[1] > 0) {
		if(four > 0) {
			four--;
			cnt[1]--;
			two++;
		} else if(two > 0) {
			two--;
			cnt[1]--;
		} else if(one > 0) {
			one--;
			cnt[1]--;
		} else {
			puts("NO");
			return 0;
		}
	}

	if(cnt[1] > 0 || cnt[2] > 0 || two < 0 || one < 0) {
		puts("NO");
	} else {
		puts("YES");
	}

    return 0;
}
