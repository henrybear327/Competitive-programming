#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const char* month[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
	char m1[100], m2[100];
	scanf("%s %s", m1, m2);

	int one, two;
	for(int i = 0; i < 7; i++) {
		if(strcmp(m1, month[i]) == 0)
			one = i;
		if(strcmp(m2, month[i]) == 0)
			two = i;
	}
	
	const int pair[] = {-3, -2, 0, 2, 3};
	bool ok = false;
	int diff = two - one >= 0 ? two - one : - ((two - one + 7) % 7); // WOW
	for(int i = 0; i < 5; i++)
		if(diff  == pair[i])
			ok = true;
		
	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}
