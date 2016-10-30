#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

bool check(char c)
{
	return c == '.' || ('0' <= c && c <= '9');
}

int main()
{
	char inp[1111];
	scanf("%s", inp);
	
	int integer = 0, decimal = 0, len = strlen(inp);
	bool active = false;
	string num = "";
	for(int i = 0; i <= len; i++) {
		if(i != len && check(inp[i])) {
			active = true;
			num += inp[i];
		} else {
			if(active == true) {
				int numLen = num.length();

				if(numLen > 3 && num[numLen - 3] == '.') {
					// has decimal
					string num1 = num.substr(0, numLen - 3);
					string num2 = num.substr(numLen - 2, 3);

					for(int i = 0; i < num1.length(); i++)
						if(num1[i] == '.')
							num1.erase(i, 1);
					integer += atoi(num1.c_str());
					decimal += atoi(num2.c_str());
				} else {
					for(int i = 0; i < numLen; i++)
						if(num[i] == '.')
							num.erase(i, 1);
					integer += atoi(num.c_str());
				}
			}

			active = false;
			num.clear();
		}
	}

	integer += decimal / 100;
	decimal %= 100;

	// printf("%d %d\n", integer, decimal);

	if(integer == 0) {
		printf("0.%02d\n", decimal);
	} else {
		if(decimal == 0) {
			if(integer >= 1000000)
				printf("%d.%03d.%03d\n", integer / 1000000, (integer / 1000) % 1000, integer % 1000);
			else if(integer >= 1000)
				printf("%d.%03d\n", integer / 1000, integer % 1000);
			else
				printf("%d\n", integer % 1000);
		} else {
			if(integer >= 1000000)
				printf("%d.%03d.%03d.%02d\n", integer / 1000000, (integer / 1000) % 1000, integer % 1000, decimal);
			else if(integer >= 1000)
				printf("%d.%03d.%02d\n", integer / 1000, integer % 1000, decimal);
			else
				printf("%d.%02d\n", integer % 1000, decimal);
		}
	}

	return 0;
}
