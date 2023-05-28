class Solution {
public:
    int cut(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)return 0;
        else if(dp[i][j]!=-1)return dp[i][j];
        else{
            int min_cost=INT_MAX;
            for(int idx=i;idx<=j;idx++){
                int cost=cuts[j+1]-cuts[i-1] + cut(i,idx-1,cuts,dp) + cut(idx+1,j,cuts,dp);
                min_cost=min(min_cost,cost);
            }
            return dp[i][j]=min_cost;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return cut(1,c,cuts,dp);
    }
};
