/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int n = dim[0], m = dim[1];
        
        int mn = m;
        for(int i = 0; i < n; i++) {
            // 000001111
            int l = -1, r = m;
            while(r - l > 1) {
                int mid = l + (r - l) / 2;
                if(binaryMatrix.get(i, mid))
                    r = mid;
                else
                    l = mid;
            }
            
            mn = min(mn, r);
        }
        
        return mn == m ? -1 : mn;
    }
};
