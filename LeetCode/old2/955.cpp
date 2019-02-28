class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        // The extra W in O(NWW) is from strcmp!
        if (A.size() == 0)
            return 0;

        //         vector<string> tmp(A.size());
        //         for(int i = 0; i < (int)A[0].length(); i++) {
        //             bool del = false;
        //             for(int j = 1; j < (int)A.size(); j++) {
        //                 if(tmp[j - 1] + A[j - 1][i] > tmp[j] + A[j][i]) {
        //                     del = true;
        //                     break;
        //                 }
        //             }
        //             if(del == false) {
        //                 for(int j = 0; j < (int)A.size(); j++) {
        //                     tmp[j] += A[j][i];
        //                 }
        //             }
        //         }

        //         return A[0].length() - tmp[0].length();

        // the idea for approach 2 in the tutorial is:
        // ["axx","ayy","baa","bbb","bcc"]
        // let's look at pos 0 for all strings, we can see that we can divide them
        // into 2 groups, one starting with a, and one starting with b why so?
        // because all the strings in group 2 won't be smaller than those in group 1
        // anyway, so we isolate them! by doing this, we can save the string compare
        // and concat cost from approach 1

        int del = 0;
        bool cut[A.size()] = {false};
        for (int i = 0; i < (int)A[0].length(); i++) {
            bool violation = false;
            for (int j = 1; j < (int)A.size(); j++) {
                if (cut[j] == false) { // same group as the prev string
                    if (A[j - 1][i] > A[j][i]) {
                        del++;
                        violation = true;
                        break;
                    }
                }
            }
            if (violation)
                continue;

            // update grouping
            for (int j = 1; j < (int)A.size(); j++) {
                if (A[j - 1][i] < A[j][i]) {
                    cut[j] = true;
                }
            }
        }

        return del;
    }
};
