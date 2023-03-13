class Solution {
public:
    int hammingWeight(uint32_t n) {
           int count=0;
        while (n) {
            // when we substract n by 1, the Lowest significant 1 is affected first, thus 
            // when we use and (&) operation the other 1's stay intact and we increment count by 1
            n &= (n-1);
            count++;
        }
        return count;
    }
};
