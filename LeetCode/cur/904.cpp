typedef pair<int, int> ii;

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        int sz = tree.size();
        if (sz == 0)
            return 0;

        vector<ii> compact;

        int cnt = 1;
        int what = tree[0];
        for (int i = 1; i < sz; i++) {
            if (tree[i] != what) {
                compact.push_back(ii(what, cnt));
                what = tree[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        compact.push_back(ii(what, cnt));

        int ans = 0;
        cnt = 0;
        for (int i = 0; i < (int)compact.size(); i++) {
            if (i < 2) {
                ans += compact[i].second;
                cnt += compact[i].second;
            } else {
                if (compact[i].first == compact[i - 2].first) {
                    cnt += compact[i].second;
                } else {
                    cnt = compact[i - 1].second;
                    cnt += compact[i].second;
                }
                ans = max(ans, cnt);
            }
        }

        ans = max(ans, cnt);
        return ans;
    }
};
