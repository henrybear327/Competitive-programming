class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
//         int diff = arr[1] - arr[0];
//         int cnt = 0;
//         int ans;
//         for(int i = 2; i < n; i++) {
//             int tmp = arr[i] - arr[i - 1];
//             if(diff != tmp) {
//                 cnt++;
//                 ans = arr[i - 1] + diff;
//             }
//         }
        
//         if(cnt != 1) {
//             cnt = 0;
//             int diff = arr[2] - arr[1];
//             ans = arr[0] + diff;
//         }
        
//         if(n == 3) {
//             int diff = arr[1] - arr[0];
//             int diff2 = arr[2] - arr[1];
            
//             if(abs(diff) < abs(diff2)) 
//                 ans = arr[1] + diff;
//             else
//                 ans = arr[0] + diff2;
//         }
        
//         return ans;
        
        for(int i = 2; i < n; i++) {
            if(arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) {
                return arr[i] + arr[i - 2] - arr[i - 1];
            }
        }
        
        return 0; // 0, 0, 0, 0...
    }
};

/*
0d 1d 2d 3d

3x + 4d = 0 + 3 - 1
3x + 5d = 0 + 3 - 2
*/
