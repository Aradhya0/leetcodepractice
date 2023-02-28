class Solution {
public:
    bool divisorGame(int n) {
        vector<int>ans(1005);
        ans[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0 && ans[i-j]==0)
                    ans[i]=1;
            }
        }
        return ans[n];
    }
};
