class Solution
{
private:
    bool check(int mid, vector<int> &houses, vector<int> &heaters)
    {
        int idx = 0;
        for (auto i : houses) {
            while (idx < heaters.size() &&
                   !(heaters[idx] - mid <= i && i <= heaters[idx] + mid))
                idx++;
            if (idx == heaters.size())
                return false;
        }
        return true;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int l = -1, r = 1e9 + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;

            if (check(mid, houses, heaters) == false)
                l = mid;
            else
                r = mid;
        }

        return r;
    }
};