#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
bool inBound(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < n);
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main()
{
    while(scanf("%d", &n) == 1) {
        int m[n][n];
        
        vector<ii> loc1, loc3;
        for(int i = 0; i < n; i++) {
            char inp[n + 2];
            scanf("%s", inp);
            for(int j = 0; j < n; j++) {
                m[i][j] = inp[j] - '0';
                
                if(m[i][j] == 3) {
                    loc3.push_back(ii(i, j));
                } else if(m[i][j] == 1) {
                    loc1.push_back(ii(i, j));
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < (int)loc1.size(); i++) {
            int x1 = loc1[i].first;
            int y1 = loc1[i].second;
            
            int tmp = INT_MAX;
            for(int j = 0; j < (int)loc3.size(); j++) {
                int x3 = loc3[j].first;
                int y3 = loc3[j].second;
                
                int diff = abs(x1 -x3) + abs(y1 - y3);
                tmp = min(tmp, diff);
            }
            
            mx = max(mx, tmp);
        }
        
        printf("%d\n", mx);
    }
    
    return 0;
}