#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

const int N = (int)1e5 + 10;
int t[20][N];

int n, k;
vector< ii > table;
vector< ii > starting;

void build()
{
    for(int j = 0; j < (int) table.size(); j++) {
	t[0][j] = table[j].second;
    }

    for(int i = 1; (1 << i) <= (int)table.size(); i++) 
	for(int j = 0; j + (1 << i) <= (int)table.size(); j++) 
	    t[i][j] = max(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
}

int spQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(t[k][l], t[k][r - (1 << k) + 1]);
}

int query(int l, int r)
{
    vector< ii >::iterator gl = upper_bound(starting.begin(), starting.end(), ii(l, INT_MAX));
    vector< ii >::iterator gr = upper_bound(starting.begin(), starting.end(), ii(r, INT_MAX));
    
    // printf("%d %d\n", gl - starting.begin(), gr - starting.begin());
    int li = (int)(gl - starting.begin()) - 1;
    int ri = (int)(gr - starting.begin()) - 1;

    // printf("%d %d\n", li, ri);

    if(li == ri) {
	// case 1 total overlap
	return r - l + 1;
    } else if(ri - li == 1) {
	// case 2 partial overlap (2 intervals)
	return max((starting[li + 1].first - l), (r - starting[ri].first + 1));
    } else {
	// case 3 total and partial overlap

	return max(spQuery(li + 1, ri - 1), max((starting[li + 1].first - l), (r - starting[ri].first + 1)));
    }
}

int main()
{
    while(scanf("%d %d", &n, &k) == 2 && n != 0) {
	// init
	table.clear();
	starting.clear();
	
	// read input
	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	
	// lisan: build (num, occurence) count table
	int prev = 0;
	for(int i = 1; i < n; i++) {
	    if(inp[i] != inp[prev]) {
		table.push_back(ii(inp[prev], i - prev));
		prev = i;
	    }
	}
	table.push_back(ii(inp[prev], n - prev));
	
	/*
	for(auto i : table)
	    printf("%d %d\n", i.first, i.second);
	printf("\n");
	*/

	// build sparse table
	build();

	// build starting pos table
	int sum = 0;
	for(int i = 0; i < (int)table.size(); i++) {
	    starting.push_back(ii(sum, table[i].first));
	    sum += table[i].second;
	}   
	starting.push_back(ii(n, INT_MAX));

	/*
	for(auto i : starting)
	    printf("%d %d\n", i.first, i.second);
	printf("\n");
	*/

	for(int i = 0; i < k; i++) {
	    // process query
	    int l, r;
	    scanf("%d %d", &l, &r);
	    printf("%d\n", query(l - 1, r - 1));
	}
    }

    return 0;
}
