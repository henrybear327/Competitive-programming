class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1, r = x; // [l, r]
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid <= x / mid)
                l = mid + 1; // one after ok
            else
                r = mid - 1; // one before ok
        }
        // l will be at the first no-ok position
        // r will be at the first ok position
        return r;

        // O(log(x))
        //         long long l = 0, r = x + 1LL; // [l, r)
        //         while(r - l > 1) {
        //             long long mid = l + (r - l) / 2;
        //             if(mid <= x / mid)
        //                 l = mid;
        //             else
        //                 r = mid;
        //         }

        //         return l;

        // // O(sqrt(x))
        // int i = 0;
        // while(1LL * i * i <= x)
        //     i++;
        // return i - 1;
    }
};
