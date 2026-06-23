class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, res = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++) {
            if (mp.count(s[r])) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};