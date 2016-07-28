#include <bits/stdc++.h>

using namespace std;

#define N 1000010
#define lsb(x) (x&(-x))
typedef long long ll;

map<int, int> lisan;
int num_cnt[N], inp[N];
int r_num_cnt[N];

int n;
struct {
	int data[N];
	void init() {
		memset(data, 0, sizeof(data));
	}

	void add(int i, int val) {
		while(i <= n) {
			data[i] += val;
			i += lsb(i);
		}
	}

	int query(int i) {
		int res = 0;
		while(i > 0) {
			res += data[i];
			i -= lsb(i);
		}
		return res;
	}
} bit;

/*
Key idea:
1. maintain a list of the occurrence of a certain number
2. Scan i from n - 2 -> 0, maintain previous mentioned list, and maintain the sum of occurrence from right to n - i using BIT
*/
int main()
{
	scanf("%d", &n);

	memset(num_cnt, 0, sizeof(num_cnt));
	
	int idx = 1;
	for(int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);
		
		if(lisan[cur] == 0) {
			num_cnt[idx]++;
			inp[i] = idx;
			
			lisan[cur] = idx++;
		} else {
			num_cnt[lisan[cur]]++;
			inp[i] = lisan[cur];
		}
	}
	
	bit.init();
	
	// from right to left
	ll ans = 0;
	memset(r_num_cnt, 0, sizeof(r_num_cnt));
	for(int i = n - 2; i >= 0; i--) {
		// update left (reduce occur)
		int prev = inp[i + 1]; // what number
		num_cnt[prev]--; 
		
		// update right
		r_num_cnt[prev]++;
		bit.add(r_num_cnt[prev], 1);
		
		int loccur = num_cnt[inp[i]];
		int roccur = bit.query(loccur - 1);
		
		//printf("%d %d\n", loccur, roccur);
		ans += roccur;
	}

	printf("%lld\n", ans);

	return 0;
}
