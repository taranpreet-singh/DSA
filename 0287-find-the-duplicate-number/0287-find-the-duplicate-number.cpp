class Solution {
public:
    int negativeMarking(vector<int>& nums) {
        for (int n : nums) {
            int idx = abs(n) - 1;
            if (nums[idx] < 0) {
                return abs(n);
            }
            nums[idx] *= -1;
        }
        return -1;
    }

    // Fast and Slow pointer
    int floydAlgo(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }

    int findDuplicate(vector<int>& nums) { return floydAlgo(nums); }
};