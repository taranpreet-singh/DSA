class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> mp;
        for (auto c : s1) {
            mp[c]++;
        }

        bool reset = true;
        unordered_map<char, int> mp_copy;
        int l = 0, r = 0;
        while (r < s2.size()) {
            char curr = s2[r];
            if (reset) {
                mp_copy = mp;
                reset = false;
            }
            if (mp_copy.count(curr)) {
                r++;
                mp_copy[curr]--;
                if (mp_copy[curr] == 0)
                    mp_copy.erase(curr);

                if (mp_copy.size() == 0)
                    return true;
            } else {
                l++;
                r = l;
                reset = true;
            }
        }

        return false;
    }
};