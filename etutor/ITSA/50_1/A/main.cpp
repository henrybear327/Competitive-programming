#include <cstdio>
#include <cstring>

int main()
{
	char inp[100];
	scanf("%s", inp);

	char cur[100];
	while(scanf("%s", cur) == 1 && strcmp(cur, "0000") != 0) {
		int a = 0, b = 0;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(i == j) {
					if(inp[i] == cur[j])
						a++;
				} else {
					if(inp[i] == cur[j])
						b++;
				}
			}
		}
		printf("%dA%dB\n", a, b);
	}

	return 0;
}
