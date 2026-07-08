class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // temprature, index

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto top = stack.top();
                stack.pop();
                res[top.second] = i - top.second;
            }
            stack.push({t, i});
        }

        return res;
    }
};