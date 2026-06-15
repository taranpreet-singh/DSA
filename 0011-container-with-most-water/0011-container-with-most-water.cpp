class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int water = 0;

        while (l < r) {
            int currCap = min(height[l], height[r]) * (r - l);
            if (currCap > water) {
                water = currCap;
            }
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return water;
    }
};