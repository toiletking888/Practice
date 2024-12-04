class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int> > grid(m);
        int N = 0, E = 0, S = 0, W = 0; 
        for(int i = 0;i < grid.size();i++){
            grid[i].resize(n);
        }
        for(int i = 0;i < walls.size();i++){
            grid[walls[i][0]][walls[i][1]] = 2;
        }
        /*for(int i = 0;i < guards.size();i++){
            grid[guards[i][0]][guards[i][1]] = 1;
        }*/
        for(int i = 0;i < guards.size();i++){
            N = guards[i][0];
            E = guards[i][1];
            S = guards[i][0];
            W = guards[i][1];
            while(N >= 0){
                if(grid[N][guards[i][1]] != 2){
                    grid[N][guards[i][1]] = 1;
                }
                else{
                    break;
                }
                N--;
            }
            while(E < n){
                if(grid[guards[i][0]][E] != 2){
                    grid[guards[i][0]][E] = 1;
                }
                else{
                    break;
                }
                E++;
            }
            while(S < m){
                if(grid[S][guards[i][1]] != 2 ){
                    grid[S][guards[i][1]] = 1;
                }
                else{
                    break;
                }
                S++;
            }
            while(W >= 0){
                if(grid[guards[i][0]][W] != 2){
                    grid[guards[i][0]][W] = 1;
                }
                else{
                    break;
                }
                W--;
            }
        }
        int ans = 0;
        for(int i = 0;i < grid.size();i++){
            ans += count(grid[i].begin(), grid[i].end(), 0);
        }
        return ans;
    }
};
// top solution
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for(auto w : walls){
            grid[w[0]][w[1]] = 2;
        }
        for(auto g : guards){
            grid[g[0]][g[1]] = 2;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for(auto g : guards){
            for(int k = 0;k < 4;k++){
                int x = g[0], y = g[1];
                int dx = dirs[k], dy = dirs[k+1];
                while(x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] != 2){
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < m;i++){
            ans += count(grid[i], grid[i]+n, 0);
        }
        return ans;
    }
};