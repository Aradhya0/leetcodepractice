class Solution {
public:
    int countOdds(int low, int high) {
           int count = 0;

        if(low % 2 != 0 )
            count++;
        else if(high % 2 != 0 )
            count++;
        
        count += (high - low) / 2;

        return count;
        
    }
};
