#include <bits/stdc++.h>

using namespace std;

int k;
char inp[111111];

int main()
{
	scanf("%d %s", &k, inp);
	
	int len = strlen(inp);
	int data[len];
	for(int i = 0; i < len; i++) {
		if('a' <= inp[i] && inp[i] <= 'z') {
			data[i] = 0;
		} else {
			data[i] = 1;
		}
	}
	
	int cnt = 1;
	vector<int> compressed;
	for(int i = 1; i < len; i++) {
		if(data[i] == data[i - 1]) {
			cnt++;
		} else {
			compressed.push_back(cnt);
			cnt = 1;
		}
	}
	compressed.push_back(cnt);
	/*
	for(auto i : compressed)
		printf("%d ", i);
	printf("\n");
	*/
	
	bool active = false;
	int ans = 0;
	int tmp = 0;
	// head tail is ok to be >= k, other must be == k
	for(int i = 0; i < (int)compressed.size(); i++) {
		if(active == false) {
			if(compressed[i] >= k) {
				active = true;
				tmp++;
			}
		} else {
			if(compressed[i] == k) {
				tmp++;
			} else {
				if(compressed[i] >= k)
					tmp++;
				tmp *= k;
				ans = max(ans, tmp);
				tmp = 0;
				i--; // current one might be the start for another one

				active = false;
			}
		}
	}

	tmp *= k;
	ans = max(ans, tmp);

	printf("%d\n", ans);

	return 0;
}
