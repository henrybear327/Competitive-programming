#include <bits/stdc++.h>

using namespace std;

struct Position {
    int pos[8];
};

int board[8][8];
vector<Position> data;

bool col[8];
void dfs(int depth)
{
    if (depth == 8) {
        Position position;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 1)
                    position.pos[j] = i;
        data.push_back(position);
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (col[j] == false) {
            bool ok = true;
            for (int k = 1; k <= depth; k++) {
                if (j - k >= 0 && board[depth - k][j - k] == 1)
                    ok = false;
                else if (j + k < 8 && board[depth - k][j + k] == 1)
                    ok = false;
            }

            if (ok == false)
                continue;

            board[depth][j] = 1;
            col[j] = true;
            dfs(depth + 1);
            board[depth][j] = 0;
            col[j] = false;
        }
    }
}

void build()
{
    memset(col, false, sizeof(col));
    memset(board, 0, sizeof(board));
    dfs(0);
}

int inp[8];
void solve(int ncase)
{
    int mn = INT_MAX;
    for (int i = 0; i < (int)data.size(); i++) {
        int sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += data[i].pos[j] != inp[j];
        }
        mn = min(mn, sum);
    }

    printf("Case %d: %d\n", ncase, mn);
}

int main()
{
    build();

    for (int ncase = 1;; ncase++) {
        if (scanf("%d", &inp[0]) == EOF)
            break;
        for (int i = 1; i < 8; i++)
            scanf("%d", &inp[i]);
        for (int i = 0; i < 8; i++)
            inp[i] -= 1;

        solve(ncase);
    }

    return 0;
}
