class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        long r = 0;

        while(abs(x) > 0)
        {
            r = x % 10;
            ans = ans * 10 + r;
            x /= 10;
        }
        if( ans > INT_MAX or ans < INT_MIN) return 0;
        return ans;

        
    }
};
