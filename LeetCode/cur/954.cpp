class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        // because that all numbers must be used
        // we can start from the smallest number
        // and greedy it out

        map<int, int>
        cnt; // if not sorted, [3, 6] you might attemp to do 6 first, then GG
        for (auto i : A)
            cnt[i]++;

        while (cnt.size() > 0) {
            int i = cnt.begin()->first;
            int target = i > 0 ? i * 2 : i / 2; // WOW!!
            while (cnt.find(i) != cnt.end()) {
                // cout << i << " " << target << " " << take << endl;

                if (cnt.find(i) != cnt.end() && cnt.find(target) != cnt.end()) {
                    cnt[i]--;
                    cnt[target]--;

                    if (cnt[i] < 0 || cnt[target] < 0) // special case 0
                        return false;

                    if (cnt[i] == 0)
                        cnt.erase(i);
                    if (cnt[target] == 0)
                        cnt.erase(target);
                } else {
                    // cout << "false" << endl;
                    return false;
                }
            }
        }

        return true;
    }
};
