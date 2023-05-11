class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int num1=nums1.size(),num2=nums2.size();
       vector<vector<int>>ak(num1+1,vector<int>(num2+1,0));
       for(int i=1;i<=num1;i++){
           for(int j=1;j<=num2;j++){
               if(nums1[i-1]==nums2[j-1]){
                   ak[i][j]=1+ak[i-1][j-1];
               }
               else{
                   ak[i][j]=max(ak[i-1][j],ak[i][j-1]);
               }
           }
       }
       return ak[num1][num2];
    }
};
