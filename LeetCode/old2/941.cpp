class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        if (A.size() < 3)
            return false;

        if (A[0] >= A[1]) // WTF
            return false;

        bool inc = true;
        bool first = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] == A[i])
                return false;

            if (A[i - 1] < A[i]) {
                if (inc == false)
                    return false;
            } else {
                if (inc) {
                    if (first) {
                        inc = false;
                        first = false;
                    } else
                        return false;
                }
            }
        }

        return first == false && inc == false; // WTF

        //         int mx = -1;
        //         int idx = -1;
        //         for(int i = 0; i < A.size(); i++) {
        //             if(A[i] > mx) {
        //                 mx = A[i];
        //                 idx = i;
        //             }
        //         }

        //         if(idx == 0 || idx == A.size() - 1) // WTF
        //             return false;

        //         for(int i = idx - 1; i >= 0; i--) {
        //             if(A[i] < A[i + 1])
        //                 continue;
        //             return false;
        //         }

        //         for(int i = idx + 1; i < A.size(); i++) {
        //             if(A[i - 1] > A[i])
        //                 continue;
        //             return false;
        //         }

        // return true;
    }
};
