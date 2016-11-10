#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		char inp[100];
		scanf("%s", inp);
		
		int num = 0;
		int even = 0, odd = 0;
		for(int i = 0; i < 12; i++) {
			num = inp[i] - '0';
			if(i % 2 == 1) {
				even += num;
			} else {
				odd += num;
			}
		}
		int v = 26 - ((odd + 3 * even) % 26) - 1;
		if(v == inp[12] - 'A')
			printf("valid\n");
		else
			printf("invalid\n");
	}

	return 0;
}
