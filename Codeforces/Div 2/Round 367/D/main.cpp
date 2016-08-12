#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int len = 30; // 1 << 30 -> 31 bits

struct Data {
	int lc, rc;
	int val;
};

#define DEPTH 30
#define N 200100 * DEPTH

struct Trie {
	// 0 is root
	Data data[N];
	int nextAvail;
	
	void init() {
		memset(data, -1, sizeof(data));
		nextAvail = 1;
	}
	
	void insert(int x) {
		insert(x, DEPTH, 0);		
	}

	void insert(int x, int shift, int node) {
		// printf("%d %d %d\n", x, shift, node);
		if(shift == -1) {
			data[node].val = x;
			
			return;
		}

		if(x & (1 << shift)) { // 1 rc
			if(data[node].rc == -1) {
				data[node].rc = nextAvail++;
			} 

			insert(x, shift - 1, data[node].rc);
		} else { // 0 lc
			if(data[node].lc == -1) {
				data[node].lc = nextAvail++;
			} 

			insert(x, shift - 1, data[node].lc);
		}
	}		

	void remove(int x) {
		bool var = true;
		remove(x, DEPTH, 0, &var);
	}

	void remove(int x, int shift, int node, bool* del) {
		if(shift == -1) {
			return;
		}
		
		int side = (x & (1 << shift)) ? data[node].rc : data[node].lc;
		remove(x, shift - 1, side, del);
		
		if(*del == true) {
			if(x & (1 << shift))
				data[node].rc = -1;
			else
				data[node].lc = -1;

			if(data[node].lc != -1 || data[node].rc != -1) 
				*del = false;
		}
	}

	int query(int x) {
		return query(x, DEPTH, 0);
	}

	int query(int x, int shift, int node) {
		if(shift == -1) {
			return data[node].val;
		}
		
		int tmp;
		if(x & (1 << shift)) {
			if(data[node].lc != -1)
				tmp = data[node].lc;
			else
				tmp = data[node].rc;
		} else {
			if(data[node].rc != -1)
				tmp = data[node].rc;
			else
				tmp = data[node].lc;
		}
		return query(x, shift - 1, tmp);
	}
} trie;

int main()
{
	int n;
	scanf("%d", &n);
	
	trie.init();	
	
	trie.insert(0);
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		char inp[1000];
		int x;
		scanf("%s %d", inp, &x);

		if(inp[0] == '+') {
			cnt[x]++;
			if(cnt[x] == 1)
				trie.insert(x);
		} else if(inp[0] == '-') {
			cnt[x]--;
			if(cnt[x] == 0) {
				trie.remove(x);
				cnt.erase(x);
			}
		} else {
			printf("%d\n", x ^ trie.query(x));
		}
	}

    return 0;
}
