class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int> > dp(m+1);
        for(int i = 0;i < dp.size();i++){
            dp[i].resize(n+1);
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 1){
                    dp[i+1][j+1] = 1 + min(dp[i][j], min(dp[i+1][j],dp[i][j+1]));
                    ans+=dp[i+1][j+1];
                }
            }
        }
        return ans;
    }
};