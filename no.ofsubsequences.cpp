class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=0,n=nums.size(),l=0,r=n-1,mod=1e9+7;
        vector<int> powr(n);
        powr[0]=1;
        for(int i=1;i<n;++i){
            powr[i]=powr[i-1]*2%mod;

        }
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r--;
            }else
            {
                res=(res+powr[r-l++])%mod;
            }
        }
        return res;


    }
};
