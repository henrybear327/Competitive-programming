// Author: Adrian Kuegel
// Date: 20. 10 2006

#include <stdio.h>
#include <assert.h>

#define MAXN (1<<17)

int a[MAXN],ps[MAXN+1];
int next_i[MAXN],prev_j[MAXN];
int ost[MAXN*4],v[MAXN*4];

int main() {
	int n,q;
	freopen("frequent.in","r",stdin);
	while(scanf("%d %d",&n,&q) == 2 && n) {
		assert(n >= 1 && n <= 100000 && q >= 1 && q <= 100000);
		int l = 0;
		for (int i=0; i<n; i++) {
			int t;
			scanf("%d",&t);
			assert(t >= -100000 && t <= 100000);
			if (!l || a[l-1] != t) {
				assert(!l || a[l-1] < t);
				a[l] = t;
				l++;
				ps[l] = ps[l-1];
			}
			++ps[l];
		}
		assert(ps[l] == n);
		for (int i=0,j=0; i<n; i++) {
			next_i[i] = j; // next_i[i] points to smallest position in ps with ps[j] >= i
			if (ps[j] == i)
				++j;
		}
		for (int i=n-1,j=l; i>=0; --i) {
			prev_j[i] = j-1; // prev_j[i] points to biggest position in ps with ps[j+1] <= i+1
			if (ps[j] == i+1)
				--j;
		}
		int offs = 1;
		while(offs < l)
			offs <<= 1;
		for (int i=0; i<l; i++) {
			ost[offs+i] = ps[i+1]-ps[i];
			v[offs+i] = a[i];
		}
		for (int i=offs+l; i<offs*2; ++i)
			ost[i] = 0;
		for (int i=offs-1; i; --i) {
			int left = ost[i*2];
			int right = ost[i*2+1];
			if (left >= right) {
				ost[i] = left;
				v[i] = v[i*2];
			}
			else {
				ost[i] = right;
				v[i] = v[i*2+1];
			}
		}
		int i,j;
		while(q--) {
			scanf("%d %d",&i,&j);
			--i;
			--j;
			assert(i >= 0 && i <= j && j < n);
			// element k in OST represents indizes ps[k] .. ps[k+1]-1
			int p1 = next_i[i];
			assert(p1 >= 0 && ps[p1] >= i && (!p1 || ps[p1-1] < i));
			int p2 = prev_j[j];
			assert(p2 >= -1 && ps[p2+1] <= j+1 && (p2+1 == l || ps[p2+2] > j+1));
			if (p2+1 < p1) { // no complete interval
				assert(p2+2 == p1);
				// element a[p1-1] occurs j-i+1 times
				printf("%d\n",j-i+1);
				continue;
			}
			int best = ps[p1]-i,sol;
			if (best) sol = a[p1-1];
			if (j-ps[p2+1]+1>best) {
				best = j-ps[p2+1]+1;
				sol = a[p2+1];
			}
			if (p2 < p1) {
				printf("%d\n",best);
				continue;
			}
			p1 += offs;
			p2 += offs;
			if (ost[p1] > best || ost[p1] == best && v[p1] < sol) {
				best = ost[p1];
				sol = v[p1];
			}
			if (ost[p2] > best || ost[p2] == best && v[p2] < sol) {
				best = ost[p2];
				sol = v[p2];
			}
			while((p1>>1) != (p2>>1)) {
				if ((p2&1) && (ost[p2-1] > best || ost[p2-1] == best && v[p2-1]<sol)) {
					best = ost[p2-1];
					sol = v[p2-1];
				}
				if (!(p1&1) && (ost[p1+1] > best || ost[p1+1] == best && v[p1+1]<sol)) {
					best = ost[p1+1];
					sol = v[p1+1];
				}
				p1 >>= 1;
				p2 >>= 1;
			}
			printf("%d\n",best);
		}
	}
	return 0;
}
