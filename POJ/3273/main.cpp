#include <cstdio>
#include <climits>

using namespace std;

#define N 100100
int data[N];
int n, m;

int check(int mid)
{	
	int sum = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		if(data[i] > mid) 
			return INT_MAX;

		if(data[i] + sum <= mid) {
			sum += data[i];
		} else {
			sum = data[i];
			cnt++;
		}
	}

	cnt++;
	
	return cnt;
}

int main()
{
	while(scanf("%d %d", &n, &m) == 2) {
		for(int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		int l = -1, r = 1000000000;
		while(r - l > 1) {
			int mid = (l + r) / 2;
				
			// 0 0 0 1 1 1 1 1
			if(check(mid) <= m)
				r = mid;
			else 
				l = mid;
		}	

		printf("%d\n", r);
	}		

	return 0;
}
