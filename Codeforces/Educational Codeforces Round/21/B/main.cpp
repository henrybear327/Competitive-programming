#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	
	long long sum = 0;
	for(int i = 0; i < k; i++) 
		sum += inp[i];
	
	long long ans = sum;
	for(int i = k; i < n; i++) {
		sum += inp[i];
		sum -= inp[i - k];

		ans += sum;
	}

	printf("%.15f\n", 1.0 * ans / (n - k + 1));

	return 0;
}
