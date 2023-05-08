class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int  major = 0;
        for(int i = 0 ; i < n ; i++) 
        {
            major += mat[i][i] + mat[i][n-i-1];
        }
        if(n%2 != 0) return major- mat[n/2][n/2];
        return major;
    }
};
