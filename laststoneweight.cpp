class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];
        sort(stones.begin(), stones.end(), greater<int>());
        while(stones.size() > 1){
            if(stones[0] == stones[1]){
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
            else{
                stones[1] = stones[0] - stones[1];
                stones.erase(stones.begin());
            }
            
            sort(stones.begin(), stones.end(), greater<int>());
        }
        if(stones.empty())
            return 0;
        return stones[0];
        
    }
};
