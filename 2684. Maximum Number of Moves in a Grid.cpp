class Solution {
public:
    int MAX(int col_index, vector<vector<int> > step){
        int m = 0;
        for(int i = 0;i < step.size();i++){
            if(step[i][col_index] > m){
                m = step[i][col_index];
            }
        }
        return m;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > step(m);
        for(vector<int> j : step){
            j.resize(n);
        }
        for(int i = 0;i <= m;i++){
            step[i][0] = 0;
        }
        int noroute = 0;
        int stop_col = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(j == 0 && (grid[j][i+1] > grid[j][i])){
                    step[j][i+1] = max(step[j][i]+1, step[j][i+1]);
                }
                else if(j == 0 && (grid[j+1][i+1] > grid[j][i])){
                    step[j][i+1] = max(step[j][i]+1, step[j+1][i+1]);
                }
                else{
                    noroute++;
                    continue;
                }

                if(grid[j-1][i+1] > grid[j][i]){
                    step[j-1][i+1] = max(step[j][i]+1, step[j-1][i+1]);
                }
                else if(grid[j][i+1] > grid[j][i]){
                    step[j][i+1] = max(step[j][i]+1, step[j][i+1]);
                }
                else if(grid[j+1][i+1] > grid[j][i]){
                    step[j+1][i+1] = max(step[j][i]+1, step[j+1][i+1]);
                }
                else{
                    noroute++;
                    continue;
                }

                if(j == m-1 && (grid[j][i+1] > grid[j][i])){
                    step[j][i+1] = max(step[j][i]+1, step[j][i+1]);
                }
                else if(j == m-1 && (grid[j-1][i+1] > grid[j][i])){
                    step[j-1][i+1] = max(step[j][i]+1, step[j-1][i+1]);
                }
                else{
                    noroute++;
                    continue;
                }
            }
            if(noroute == m){
                stop_col = i;
                noroute = 0;
                break;
            }
            else{
                noroute = 0;
            }
        }
        if(stop_col == 0){
            return 0;
        }
        else{
            return MAX(stop_col, step);
        }
    }
};
// top solution
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<int> dp(m);
        for(int j = 1;j < n;++j){
            int leftTop = 0;
            bool found = false;
            for(int i = 0;i < m;++i){
                int curr = -1;
                int nextLeftTop = dp[i];
                if(i-1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1]){
                    curr = max(curr, leftTop + 1);
                }
                if(dp[i] != -1 && grid[i][j] > grid[i][j-1]){
                    curr = max(curr, dp[i] + 1);
                }
                if(i+1 < m && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1]){
                    curr = max(curr, dp[i+1] + 1);
                }
                dp[i] = curr;
                found = found || (dp[i] != -1);
                leftTop = nextLeftTop;
            }
            if(!found) break;
            res = j;
        }
        return res;
    }
};