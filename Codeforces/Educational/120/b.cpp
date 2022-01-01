#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int rating[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &rating[i]);
        }

        char inp[n + 3];
        scanf("%s", inp);

        vector<ii> like;
        vector<ii> dislike;
        for (int i = 0; i < n; i++) {
            if (inp[i] == '1') {
                like.push_back(ii{rating[i], i});
            } else {
                dislike.push_back(ii{rating[i], i});
            }
        }

        sort(like.begin(), like.end());
        reverse(like.begin(), like.end());
        sort(dislike.begin(), dislike.end());
        reverse(dislike.begin(), dislike.end());

        int score = n;
        for (auto &cand : like) {
            rating[cand.second] = score;
            score--;
        }
        for (auto &cand : dislike) {
            rating[cand.second] = score;
            score--;
        }

        for (int i = 0; i < n; i++)
            printf("%d%c", rating[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
