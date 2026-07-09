class Solution {
public:
    int binSearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) / 2);
            if (nums[m] > target)
                r = m - 1;
            else if (nums[m] < target)
                l = m + 1;
            else
                return m;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (idx > 0 && nums[idx - 1] == target) {
            return idx - 1;
        } else {
            return -1;
        }
    }
};