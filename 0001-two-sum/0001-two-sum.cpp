class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        // for (int i = 0; i < len-1; i++) {
        //     for (int j=i+1; j< len; j++){
        //         if (nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }

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