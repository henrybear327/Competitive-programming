#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// handle special cases first
// [], "", ...
// range of input?
struct Data {
    int start;
    int end;
    int height;

    bool operator<(const Data &others) const
    {
        return height < others.height;
    }
};

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

// observation
// all pts in ans are the pq.top() at certain point of time
class Solution
{
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> ans;
        if (buildings.size() == 0)
            return ans;

        // sort by starting point
        vector<iii> actions; // (starting/ending pos, (action, who))
        for (int i = 0; i < (int)buildings.size(); i++) {
            actions.push_back(iii(buildings[i][0], ii(1, i)));
            actions.push_back(iii(buildings[i][1], ii(-1, i)));
        }
        sort(actions.begin(), actions.end());
        actions.push_back(iii(actions.back().first, ii(-1, INT_MAX))); // dummy

        priority_queue<Data> pq;
        pq.push(Data{-1, -1, 0});

        int n = (int)actions.size();
        for (int i = 0; i < n - 1; i++) { // disregard the last one
            int orig =
                pq.top().height; // KEY POINT! Since same pos will all be done in one
            // go, this "prev top" value is precious!

            // delete, pop outdated ones that's on top
            // guard pq dummy node
            while (pq.size() > 1 && pq.top().end <= actions[i].first) {
                pq.pop();
            }

            // insert
            // insert all intervals
            // if same position, do batch del/ins
            while (i + 1 < n && actions[i].first == actions[i + 1].first) {
                // this is the delete operation!
                while (pq.size() > 1 && pq.top().end <= actions[i].first) {
                    pq.pop();
                }

                if (actions[i].second.first == 1) { // perform insert operation
                    int idx = actions[i].second.second;
                    pq.push(
                        Data{buildings[idx][0], buildings[idx][1], buildings[idx][2]});
                }
                i++;
            }

            if (actions[i].second.first ==
                1) { // don't forget the single interval in range case!
                int idx = actions[i].second.second;
                pq.push(Data{buildings[idx][0], buildings[idx][1], buildings[idx][2]});
            }

            if (pq.top().height != orig) { // add answer!
                ans.push_back(ii(actions[i].first, pq.top().height));
            }
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif