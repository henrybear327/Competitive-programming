// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int orig = n;
        int ret = 0;
        char tmpBuffer[10];
        while (n > 0) {
            // cout << n << endl;
            int tmp = read4(tmpBuffer);
            // cout << tmp << endl;

            if (tmp == 0)
                break;

            if (n >= tmp)
                n -= tmp;
            else
                n = 0;
            int r = ret;
            for (int i = r; i < r + tmp && i < orig; i++) {
                buf[i] = tmpBuffer[i - r];
                ret++;
            }
        }
        buf[ret] = '\0';
        return ret;
    }
};