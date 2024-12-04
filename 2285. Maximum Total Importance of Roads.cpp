class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n, 0);
        long long ans = 0;
        for(auto& v : roads){
            for(int i : v){
                freq[i]++;
            }
        }
        sort(freq.begin(), freq.end());
        int token = 1;
        for(int i = 0;i < freq.size();i++){
            for(int j = 0;j < freq[i];j++){
                ans += token;
            }
            token++;
        }
        return ans;
    }
};