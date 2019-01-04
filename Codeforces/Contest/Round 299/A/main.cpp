#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const char* number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
						"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* number1[] = {" ", " ", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main()
{
	int n;
	scanf("%d", &n);

	if(n < 20)
		printf("%s\n", number[n]);
	else {
		if(n % 10 == 0)
			printf("%s\n", number1[n / 10]);
		else
			printf("%s-%s\n", number1[n / 10], number[n % 10]);
	}
	
    return 0;
}
