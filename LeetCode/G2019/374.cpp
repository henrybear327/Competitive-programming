// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int ret = guess(mid);
            if (ret == -1)
                r = mid - 1; // :)
            else if (ret == 1)
                l = mid + 1; // :)
            else
                return mid;
        }

        return -1;

        // my binary search
        //         long long int l = 0, r = 1LL * n + 1;
        //         while(r - l > 1) {
        //             long long int mid = l + (r - l) / 2;
        //             int ret = guess(mid);
        //             if(ret == -1)
        //                 r = mid;
        //             else if(ret == 1)
        //                 l = mid;
        //             else
        //                 return mid;
        //         }

        //         return l;
    }
};
