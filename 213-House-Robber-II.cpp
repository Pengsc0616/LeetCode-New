class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int rob = 0; // Max profit if I rob this time
        int notRob = 0; // Max profit if I don't rob this time
        for(int i=0; i<nums.size()-1; i++) {
            int num = nums[i];
            int preRob = rob;
            int preNotRob = notRob;
            rob = preNotRob + num;
            notRob = max(preRob, preNotRob);
        }
        int rob2 = 0; // Max profit if I rob this time
        int notRob2 = 0; // Max profit if I don't rob this time
        for(int i=1; i<nums.size(); i++) {
            int num = nums[i];
            int preRob = rob2;
            int preNotRob = notRob2;
            rob2 = preNotRob + num;
            notRob2 = max(preRob, preNotRob);
        }
        return max(max(max(rob, notRob), rob2), notRob2);
    }
};