#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = n + 1; ; i++) {
		int year = i;
		int cnt[10] = {0};
		bool err = false;
		while(year > 0) {
			if(cnt[year % 10] == 1) {
				err = true;
				break;
			}
			cnt[year % 10] = 1;
			year /= 10;
		}

		if(err == false) {
			printf("%d\n", i);
			break;
		}
	}	

	return 0;
}
