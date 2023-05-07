class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        vector<int> ans,dp;
        for (auto i:a) {
            int len = lower_bound(dp.begin(), dp.end(), i + 1) - dp.begin();
            if (len == dp.size()) {
                dp.push_back(i);
            } else {
                dp[len] = i;
            }
            ans.push_back(len + 1);
        }
        return ans;
    }
};
