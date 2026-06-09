class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        unordered_map<int, int> numToIndex;

        for (int i = 0; i < len; i++) {
            int diff = target - nums[i];
            if (numToIndex.count(nums[i])){
                return {numToIndex[nums[i]], i};
            }
            numToIndex[diff] = i;
        }

        return {};
    }
};