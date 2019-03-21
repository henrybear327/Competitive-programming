class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int idx = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // [i, j)
            int digits = 0;
            int diff = j - i;
            while (diff > 0)
                digits++, diff /= 10;

            if (digits + 1 <= j - i) {
                // compress
                chars[idx++] = chars[i];
                diff = j - i;
                int nxt = idx + digits;
                while (diff > 0) {
                    chars[idx + digits - 1] = (diff % 10) + '0';
                    diff /= 10;
                    digits--;
                }
                idx = nxt;
            } else {
                // don't compress
                for (int x = i; x < j; x++)
                    chars[idx++] = chars[i];
            }

            // update i
            i = j;

            // cout << idx << endl;
            // for(auto x : chars)
            //     cout << x;
            // cout << endl;
        }

        return idx;
    }
};
