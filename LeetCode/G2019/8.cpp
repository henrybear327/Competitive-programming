class Solution
{
public:
    int myAtoi(string str)
    {
        // 2 pass
        // mark the starting and ending positions

        int n = str.size();
        int left = -1, right = -1;
        bool isNegative = false;
        for (int i = 0; i < n; i++) {
            if (str[i] == ' ')
                continue;
            if (str[i] == '-' || str[i] == '+' || '0' <= str[i] && str[i] <= '9') {
                int j = i;
                if (str[j] == '-') {
                    isNegative = true;
                    j++;
                } else if (str[j] == '+') {
                    j++;
                }
                left = j;
                while (j < n) {
                    if ('0' <= str[j] && str[j] <= '9') {
                        j++;
                    } else {
                        break;
                    }
                }
                right = j;
                break;
            } else {
                break;
            }
        }

        // return 0 if error occurred
        if (left == -1)
            return 0;

        // convert the number
        // cout << left << " " <<  right << endl;
        int ans = 0;
        for (int i = left; i < right; i++) {
            int d = str[i] - '0';
            if (isNegative) {
                d = -d;
                if (ans < (INT_MIN - d) / 10)
                    return INT_MIN;
                ans = ans * 10 + d;
            } else {
                if (ans > (INT_MAX - d) / 10)
                    return INT_MAX;
                ans = ans * 10 + d;
            }
        }
        return ans;
    }
};
