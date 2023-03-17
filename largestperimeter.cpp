class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    //any tringle sum of smaller two side greater than 3rd side...so we check that condition, a+b>c where a<b<c
    
    
    for(int i=nums.size()-1;i>=2;i--){
        //check the triangle valid condition
        if(nums[i-1]+nums[i-2]>nums[i]){
            return(nums[i]+nums[i-1]+nums[i-2]); //perimeter
        }
    }
    
    return 0; //return 0
        
    }
};
