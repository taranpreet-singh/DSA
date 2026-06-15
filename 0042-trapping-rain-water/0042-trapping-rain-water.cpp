class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = height[l], rmax = height[r];
        int water = 0;
        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                water += lmax - height[l];
            } else {
                r--;
                rmax = max(rmax, height[r]);
                water += rmax - height[r];
            }
        }
        return water;
    }
};