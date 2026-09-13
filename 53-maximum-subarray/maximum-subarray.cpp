// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int n = nums.size();
//         int maxi = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = 0;

//                 for (int k = i; k <=j; k++) {
//                     sum += nums[k];
//                 }
//                  maxi = max(sum, maxi);
//             }
//         }
//      return maxi;
//  }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             int sum = 0;

//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 maxi = max(maxi, sum);
//             }
//         }

//         return maxi;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for (int x : nums) {
            sum += x;
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }

        return maxi;
    }
};