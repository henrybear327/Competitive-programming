#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

char buf[1111];

struct Scoreboard {
    int team;
    int solved;
    int penalty;
};

void solve()
{
    map<int, vector<ii>> score; // attemps, time
    for (int i = 1; i <= 100; i++)
        score[i] = vector<ii>(10, ii(0, -1));
    bool hasSubmission[111] = {false};
    while (fgets(buf, 1111, stdin) != NULL && buf[0] != '\n') {
        int team, p, t;
        char command[10];

        sscanf(buf, "%d %d %d %s", &team, &p, &t, command);
        if (command[0] == 'C') {
            if (score[team][p].second == -1)
                score[team][p].second = t;
        } else if (command[0] == 'I') {
            if (score[team][p].second == -1)
                score[team][p].first++;
        }

        hasSubmission[team] = true;
    }

    vector<Scoreboard> ans;
    for (int i = 1; i <= 100; i++) {
        int solved = 0;
        int penalty = 0;
        for (int j = 1; j <= 9; j++) {
            if (score[i][j].second != -1) {
                solved++;
                penalty += 20 * score[i][j].first + score[i][j].second;
            }
        }

        // if (solved > 0) { // GG
        if (hasSubmission[i]) {
            ans.push_back(Scoreboard{i, solved, penalty});
        }
    }

    sort(ans.begin(), ans.end(), [](const Scoreboard &a, const Scoreboard &b) {
        if (a.solved == b.solved) {
            if (a.penalty == b.penalty)
                return a.team < b.team;
            return a.penalty < b.penalty;
        }
        return a.solved > b.solved;
    });
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d %d %d\n", ans[i].team, ans[i].solved, ans[i].penalty);
    }
}

int main()
{
    fgets(buf, 1111, stdin);
    int ncase;
    sscanf(buf, "%d", &ncase);
    fgets(buf, 1111, stdin);
    while (ncase--) {
        solve();
        if (ncase)
            printf("\n");
    }

    return 0;
}
