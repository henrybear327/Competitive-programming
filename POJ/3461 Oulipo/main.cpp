#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	while(n--) {

		char inp[1111111];
		scanf("%s", inp);
		int len = strlen(inp), plen = strlen(inp);
		inp[len] = '$';
		inp[len + 1] = '\0';
		scanf("%s", inp + len + 1);

		// z algorithm
		len = strlen(inp);
		int z[len];
		z[0] = 0; // initial

		int l = 0, r = 0; // z box bound [l, r]
		for(int i = 1; i < len; i++) {
			if(i > r) { // i not in z box
				l = r = i; // z box contains itself only
				while(r < len && inp[r - l] == inp[r])
					r++;
				z[i] = r - l;
				r--;
			} else { // i in z box
				if(z[i - l] + i < r)
					z[i] = z[i - l];
				else {
					l = i;
					while(r < len && inp[r - l] == inp[r])
						r++;
					z[i] = r - l;
					r--;
				}
			}
		}
		
		int ans = 0;
		for(int i = plen; i < len; i++)
			if(z[i] >= plen)
				ans++;
		printf("%d\n", ans);
	}

	return 0;
}
