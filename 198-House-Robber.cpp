
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0; // Max profit if I rob this time
        int notRob = 0; // Max profit if I don't rob this time
        for(const auto & num: nums) {
            int preRob = rob;
            int preNotRob = notRob;
            rob = preNotRob + num;
            notRob = max(preRob, preNotRob);
        }
        return max(rob, notRob);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)  return nums[0];
//         vector<int> max_(nums.size(),0);
//         max_[0] = nums[0];
//         max_[1] = max(nums[0], nums[1]);
//         for(int i=2; i<nums.size(); i++){
//             max_[i] = max( (max_[i-2]+nums[i]), max_[i-1] );
//             //為什麼不用在乎前一個(的值是怎麼來的)有沒有用到 是因為 如果前一個沒有用到 那麼就會是max_[i-2]
//         }
//         return max_[nums.size()-1];
//     }
// public:
//     //vector<int> max_(nums.size(),0);
// };