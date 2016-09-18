#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	char inp[50100];
	scanf("%s", inp);

	int len = strlen(inp);
	if(len < 26) {
		printf("-1\n");
		return 0;
	} else {
		int q = 0;
		map<char, int> cnt;
		for(int i = 0; i < 26; i++) {
			if(inp[i] == '?')
				q++;
			else 
				cnt[inp[i]]++;
		}

		if(cnt.size() + q == 26) {
			// has solution
			vector<char> cand;
			for(int i = 0; i < 26; i++) {
				if(cnt[i + 'A'] == 0)
					cand.push_back(i + 'A');
			}
			int idx = 0;
			for(int i = 0; i < 26; i++) {
				if(inp[i] == '?') {
					printf("%c", cand[idx++]);
				} else {
					printf("%c", inp[i]);
				}
			}
			for(int j = 26; j < len; j++)
				printf("%c", inp[j] == '?' ? 'A' : inp[j]);

			return 0;
		}

		for(int i = 26; i < len; i++) {
			// drop i - 26
			if(inp[i - 26] == '?')
				q--;
			else {
				cnt[inp[i - 26]]--;
				if(cnt[inp[i - 26]] == 0)
					cnt.erase(inp[i - 26]);
			}

			// add i
			if(inp[i] == '?')
				q++;
			else 
				cnt[inp[i]]++;

			// check
			if(cnt.size() + q == 26) {
				// has solution
				vector<char> cand;
				for(int j = 0; j < 26; j++) {
					if(cnt[j + 'A'] == 0)
						cand.push_back(j + 'A');
				}
				int idx = 0;
				for(int j = 0; j < i - 26 + 1; j++)
					printf("%c", inp[j] == '?' ? 'A' : inp[j]);
				for(int j = i - 26 + 1; j <= i; j++) {
					if(inp[j] == '?') {
						printf("%c", cand[idx++]);
					} else {
						printf("%c", inp[j]);
					}
				}
				for(int j = i + 1; j < len; j++)
					printf("%c", inp[j] == '?' ? 'A' : inp[j]);

				return 0;
			}
		}
	}
	printf("-1\n");

	return 0;
}
