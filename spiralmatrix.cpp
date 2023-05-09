class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (m == 1)
            return mat[0];
        vector<int> ans(m * n);
        for (int a = 0, i = 0, j = 0, itv = 0, side = 0; a < m * n; a++) {
            ans[a] = mat[i][j];
            if (side == 0) {
                j++;
                if (j == n - itv - 1) {
                    side++;
                } else if (j == n) {//only when n == 1
                    j--;
                    side++;
                    i++;
                }
            } else if (side == 1) {
                i++;
                if (i == m - itv - 1)
                    side++;
            } else if (side == 2) {
                j--;
                if (j == itv)
                    side++;
            } else if (side == 3) {
                i--;
                if (i == itv + 1) {
                    side = 0;
                    itv++;
                }
            }
        }
        return ans;
    }
};
