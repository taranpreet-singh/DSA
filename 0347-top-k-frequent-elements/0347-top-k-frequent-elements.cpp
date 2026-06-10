class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> vec(nums.size() + 1);
        for (int num : nums) {
            freq[num]++;
        } // O(n)

        for (const auto& entry : freq) {
            vec[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = vec.size() - 1; i > 0; i--) {
            for (int n : vec[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
        // for (auto& [key, val] : freq) {
        //     arr.push_back({val, key});
        // } // O(n)

        // sort(arr.rbegin(), arr.rend()); // O(nlogn)

        // vector<int> res;
        // for (int i = 0; i < k; i++) {
        //     res.push_back(arr[i].second);
        // }

        // return vector<int>(res.begin(), res.begin() + k);
    }
};