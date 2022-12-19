class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k+1;
        int l = -10001;
        int r = 10001;
        while(l < r) {
            int p = l+(r-l)/2;
            // cout << p << " ";
            if(lessEqualPCount(nums, p) >= k) r = p;
            else l = p + 1; 
        }
        return l;
    }
    int lessEqualPCount(vector<int>& nums, int p) {
        int ret = 0;
        for(const auto n: nums) if(n <= p) ret++;
        return ret;
    }
};

// why this cannot work? Think about when the vector is 1 2 3 5 7 11 13
// And the p is 6 想清楚你寫的binary search 你的答案會是最小的嗎
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int l = -10001;
//         int r = 10001;
//         while(l < r) {
//             int p = l+(r-l)/2;
//             // cout << p << " ";
//             if(greaterEqualPCount(nums, p) <= k) r = p;
//             else l = p + 1; 
//         }
//         return l;
//     }
//     int greaterEqualPCount(vector<int>& nums, int p) {
//         int ret = 0;
//         for(const auto n: nums) if(n >= p) ret++;
//         return ret;
//     }
// };