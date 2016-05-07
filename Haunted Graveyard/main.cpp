#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

#define INT_MAX (1 << 30)
using namespace std;

int m[33][33];

#define GRASS 0
#define STONE 1
#define HOLE 2

int w, h;
int convert(int x, int y)
{
    if((0 <= x && x < w) && (0 <= y && y < h))
	return x * h + y;    
    return -1;
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main()
{
    while(scanf("%d %d", &w, &h) == 2 && (w || h) ) {
	memset(m, 0, sizeof(m));
	for(int i = 0; i < 33; i++)
	    for(int j = 0; j < 33; j++)
		m[i][j] = 0;

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
	    int a, b;
	    scanf("%d %d", &a, &b);
	    m[a][b] = STONE;
	}
	
	int nn;
	scanf("%d", &nn);
	map< pair<int, int>, pair< pair<int, int>, int > > info;
	for(int i = 0; i < nn; i++) {
	    int a, b, c, d, e;
	    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	    m[a][b] = HOLE;
	    info.insert(make_pair(make_pair(a, b), make_pair(make_pair(c, d), e)));
	}
	
	vector< pair<int, pair<int, int> > >edge;
	// convert to an adjacency matrix
	for(int i = 0; i < w; i++) {
	    for(int j = 0; j < h; j++) {
		if(i == w - 1 && j == h - 1)
		    continue;

		if(m[i][j] == GRASS) {
		    for(int k = 0; k < 4; k++) {
			int x1 = i + dx[k];
			int y1 = j + dy[k];
			if(convert(x1, y1) != -1) {
			    if(m[x1][y1] == STONE)
				continue;
			    edge.push_back(make_pair(1, make_pair(convert(i, j), convert(x1, y1))));
			}
		    }
		} else if(m[i][j] == STONE) {
		    continue;
		} else  {
		    pair< pair<int, int>, int> tmp = info[make_pair(i, j)];
		    edge.push_back(make_pair(tmp.second, make_pair(convert(i, j), 
			convert(tmp.first.first, tmp.first.second))));
		}
	    }
	}
	
	int lim = w * h;
	int dst[1000];
	for(int i = 0; i < 1000; i++)
	    dst[i] = INT_MAX;
	dst[0] = 0;
	
	bool loop = false;
	int cnt[1000] = {0};
	bool hasChange = false;

	for(int i = 0; loop == false; i++) {
	    for(int j = 0; j < (int)edge.size(); j++) {
		int u = edge[j].second.first, v = edge[j].second.second;
		int w = edge[j].first;
		// printf("%d %d %d\n", u, v, w);
		if(dst[u] != INT_MAX && dst[v] > dst[u] + w) {
		    dst[v] = dst[u] + w;
		    hasChange = true;

		    if(cnt[v] == lim - 1) {
			loop = true;
			break;
		    }
		    cnt[v]++;
		}
	    }
	    
	    /*
	    for(int j = 0; j < lim; j++)
		printf("%d %d\n", j, dst[j]);
	    printf("\n");
	    */

	    if(hasChange == false)
		break;
	    hasChange = false;
	}

	if(loop == true)
	    printf("Never\n");
	else if(dst[lim - 1] == INT_MAX) 
	    printf("Impossible\n");
	else
	    printf("%d\n", dst[lim - 1]);
    }

    return 0;
}
