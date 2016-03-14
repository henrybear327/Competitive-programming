#include <bits/stdc++.h>

using namespace std;

typedef struct state {
    int jug[3];
    int water_so_far;
} State;

int DP[201][201][201];

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int lim[3], d;
        scanf("%d %d %d %d", &lim[0], &lim[1], &lim[2], &d);

        for (int i = 0; i <= lim[0]; i++)
            for (int j = 0; j <= lim[1]; j++)
                for (int k = 0; k <= lim[2]; k++)
                    DP[i][j][k] = INT_MAX;

        int res[201];
        for (int i = 0; i < 201; i++)
            res[i] = INT_MAX;

        queue<State> q;

        State curr = {{0, 0, lim[2]}, 0};
        q.push(curr);

        while (!q.empty()) {
            State curr_orig = curr = q.front();
            q.pop();

            if (curr.water_so_far >= res[d]) // is res[d] is not INT_MAX, then just check for d because d is now present
                continue;

            if (curr.water_so_far >= DP[curr.jug[0]][curr.jug[1]][curr.jug[2]]) //Don't need to work on the same tuple on deeper level
                continue;

            DP[curr.jug[0]][curr.jug[1]][curr.jug[2]] = curr.water_so_far; //update data
            for (int k = 0; k < 3; k++)
                res[curr.jug[k]] = min(res[curr.jug[k]], curr.water_so_far);

            // calculate 6 combination
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    curr = curr_orig;
                    if (i == j)
                        continue;

                    // i to j
                    if (curr.jug[i] + curr.jug[j] <= lim[j]) {
                        curr.water_so_far += curr.jug[i];
                        curr.jug[j] += curr.jug[i];
                        curr.jug[i] = 0;
                    } else {
                        curr.water_so_far += (lim[j] - curr.jug[j]);
                        curr.jug[i] -= (lim[j] - curr.jug[j]);
                        curr.jug[j] = lim[j];
                    }

                    q.push(curr);
                }
            }
        }

        for (int i = d; i >= 0; i--) {
            if (res[i] != INT_MAX) {
                printf("%d %d\n", res[i], i);
                break;
            }
        }
    }

    return 0;
}
