class Solution {
public:
    vector<int> divisionMethod(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int prod = 1, zeroCount = 0;
        for (int num : nums) {
            if (num != 0) {
                prod *= num;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return res;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                res[i] = (nums[i] == 0) ? prod : 0;
            } else {
                res[i] = prod / nums[i];
            }
        }

        return res;
    } // T: O(n) S: O(1)

    vector<int> prefixSuffixMethod(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;

    } // T: O(n) S: O(1)

    vector<int> productExceptSelf(vector<int>& nums) {
        return prefixSuffixMethod(nums);
    }
};