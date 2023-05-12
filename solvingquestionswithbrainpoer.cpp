class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size(), jumpInd = 0;
        long long pick = 0, notPick = 0;
        vector<long long> dp(n, -1);

        for(int ind = n - 1; ind >= 0; ind--) {
            jumpInd = ind + questions[ind][1] + 1;

            pick = questions[ind][0];
            if (jumpInd < n) pick +=  dp[jumpInd];

            notPick = 0;
            if (ind + 1 < n) notPick += dp[ind + 1];

            dp[ind] = max(pick, notPick);
        }
        return dp[0];
    }
};
