class Solution {
private:
    int dp[101][101][101];
    int mod = 1e9 + 7;
    int helper(vector<int>& group, vector<int>& profit,int minProfit,int i,int n,int prft){
        if(n < 0) return 0;
        if(i == group.size()) return prft >= minProfit;
        if(dp[i][n][prft] != -1) return dp[i][n][prft];
        
        return dp[i][n][prft] = (helper(group,profit,minProfit,i+1,n-group[i],min(minProfit,prft + profit[i])) + helper(group,profit,minProfit,i+1,n,prft)) % mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(group,profit,minProfit,0,n,0);
    }
};
