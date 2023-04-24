class Solution {
public:
    int Getcount(vector<int>& spells, vector<int>& potions, long long success,int x){
        int high=potions.size()-1;
        int low=0;
        int ans=potions.size();// don't take this 0
        while(low<=high){
            int mid=low+(high-low)/2;
            long long product=(long long) x*potions[mid]; // this will over flow for int

            if(product>=success){
                ans=mid;
                high=mid-1;
            }   
            else{
                low=mid+1;
            }     
            
        }
        return potions.size()-ans;


    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;++i){
             int var=Getcount(spells,potions,success,spells[i]);
             ans.push_back(var);

        }
        return ans;
    }
};
