#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 10000000

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int row, column;
inline bool bounded(int x, int y)
{
    return 0 <= x && x < row && 0 <= y && y < column;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
        scanf("%d %d", &row, &column);

        int tmp[row][column];
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                scanf("%d", &tmp[i][j]);

        vector<vii> AdjList;
        AdjList.assign(row * column, vii()); // assign blank vectors of pair<int, int>s to AdjList
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                for(int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(bounded(x, y)) {
                        AdjList[i * column + j].push_back(make_pair(x * column + y, tmp[x][y])); // directed graph
                    }
                }
            }
        }

        //Dijkstra

        vector<int> dist;
        dist.assign(row * column, INF);

        dist[0] = tmp[0][0];
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(make_pair(0, 0));

        while(!pq.empty()) {
            ii curr = pq.top();
            pq.pop();

            int dist_to_s = curr.first;
            int connect_with = curr.second;

            if(dist_to_s > dist[connect_with])
                continue;
            for(int i = 0; i < (int)AdjList[connect_with].size(); i++) {
                ii &next = AdjList[connect_with][i];
                if(dist[connect_with] + next.second < dist[next.first]) {
                    dist[next.first] = dist[connect_with] + next.second;
                    pq.push(make_pair(dist[next.first], next.first));
                }
            }
        }
        /*
            for(int i = 0; i < row; i++)
                for(int j = 0; j < column; j++)
                    printf("%3d%c", dist[i * column + j], j == column - 1 ? '\n' : ' ');
            printf("\n");
        */
        printf("%d\n", dist[row * column - 1]);
    }

    return 0;
}
