class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int pivot = l;

        int res = binarySearch(nums, target, 0, pivot - 1);
        if (res != -1) {
            return res;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};