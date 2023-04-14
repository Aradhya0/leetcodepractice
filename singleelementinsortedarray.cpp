class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int hi = nums.size()-1;
        int lo = 0;

        while(lo<hi){
            int m = (hi+lo)/2;
            if((m-lo)%2==0){
                if(nums[m]==nums[m-1]){
                    hi = m - 2;
                }
                else if(nums[m]==nums[m+1]){
                    lo = m+2;
                }
                else break;
                
            }
            else {
                if(nums[m]==nums[m+1]){
                    hi = m - 1;
                }
                else if(nums[m]==nums[m-1]){
                    lo = m+1;
                }
                else break;
            }
        }
        return nums[(hi+lo)/2];
    }
};
