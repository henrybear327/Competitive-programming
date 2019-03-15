class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        vector<int> compress, type;
        int n = tree.size();
        compress.reserve(n);
        type.reserve(n);
        if (n == 0)
            return 0;

        for (int i = 0; i < n;) {
            int r = i;
            while (r < n && tree[r] == tree[i]) {
                r++;
            }

            compress.push_back(r - i);
            type.push_back(tree[i]);
            i = r;
        }

        n = compress.size();
        int ans = 0;
        int l = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (i - l <= 1)
                tmp += compress[i];
            else {
                if (type[i - 2] == type[i])
                    tmp += compress[i];
                else {
                    l = i - 1;
                    tmp = compress[i - 1] + compress[i];
                }
            }

            ans = max(ans, tmp);
        }

        return ans;
    }
};