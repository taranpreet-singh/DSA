class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        } // O(n)

        vector<pair<int, int>> arr;

        for (auto& [key, val] : freq) {
            arr.push_back({val, key});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }

        return vector<int>(res.begin(), res.begin() + k);
    }
};