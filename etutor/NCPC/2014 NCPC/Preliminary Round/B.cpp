#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--) {
	int number;
	scanf("%d", &number);
	int cnt = 0;
	while(number) {
	    if(number & 1)
		cnt++;
	    number >>= 1;
	}

	if(cnt % 2 == 1)
	    printf("1\n");
	else
	    printf("0\n");
    }
    return 0;
}
