class Solution {
public:
int bestTeamScore(vector<int>& scores, vector<int>& ages) {

   vector<pair<int,int>> p;
   for(int i=0;i<scores.size();i++){
       p.push_back(make_pair(ages[i],scores[i]));
   } 
   sort(p.begin(),p.end());

   int n = p.size();
   vector<int> dp(n, 0);

   int ans = 0;
   for (int i = 0; i < n; i++) {
       dp[i] = p[i].second;
       for (int j = 0; j < i; j++) {
           if (p[j].second <= p[i].second) {
               dp[i] = max(dp[i], dp[j] + p[i].second);
           }
       }
       ans = max(ans, dp[i]);
   }
   return ans;
    }
};
