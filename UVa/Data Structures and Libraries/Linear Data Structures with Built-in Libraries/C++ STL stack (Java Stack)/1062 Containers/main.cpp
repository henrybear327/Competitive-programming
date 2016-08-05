#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    char inp[10000];
    int ncase = 1;
    while (scanf("%s", inp) == 1 && strcmp(inp, "end") != 0) {
		int len = strlen(inp);
		
		vector<char> s;
		for(int i = 0; i < len; i++) {
			bool ok = false;
			char c = inp[i];
			for(int j = 0; j < (int)s.size(); j++) {
				if(c <= s[j]) {
					s[j] = c;
					ok = true;
					break;
				}

			}
			if(!ok)
				s.push_back(c);

		}
		printf("Case %d: %d\n", ncase++, (int)s.size());
    }

    return 0;
}
