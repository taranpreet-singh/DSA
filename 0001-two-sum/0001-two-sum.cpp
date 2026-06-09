class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        unordered_map<int, int> values;

        for (int i = 0; i < len; i++) {
            int remaining = target - nums[i];
            if (values.count(nums[i])){
                return {values[nums[i]], i};
            }
            values[remaining] = i;
        }

        return {};
    }
};