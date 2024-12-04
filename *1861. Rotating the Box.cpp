class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<int> rockNumberEachRow(m);
        vector<vector<char> > ans(n);
        for(int i = 0;i < ans.size();i++){
            ans[i].resize(m, '.');
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(box[i][j] == '#'){
                    rockNumberEachRow[i]++;
                }
                if(box[i][j] == '*'){
                    ans[j][(m-1)-i] = '*';
                }
                
            }
        }
        for(int i = 0;i < ans.size();i++){
            for(int j = 0;j < ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;i < n;j++){
                if(ans[j][(m-1)-i] == '*'){
                    for(int k = 1;k <=rockNumberEachRow[i];k++){
                        ans[j-k][(m-1)-i] = '#';
                    }
                    break;
                }
            }
        }
        return ans;
    }
};