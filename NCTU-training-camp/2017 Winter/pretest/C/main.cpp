#include <bits/stdc++.h>

using namespace std;

const char* vowels = "AOYEUIaoyeui";

int main()
{
	char inp[111];
	scanf("%s", inp);

	int len = strlen(inp);
	for(int i = 0; i < len; i++) {
		bool skip = false;
		for(int j = 0; j < 12; j++)
			if(inp[i] == vowels[j])
				skip = true;

		if(skip == false) {
			printf(".");
			
			if('A' <= inp[i] && inp[i] <= 'Z')
				inp[i] = inp[i] - 'A' + 'a';
			printf("%c", inp[i]);
		}
	}

	return 0;
}
