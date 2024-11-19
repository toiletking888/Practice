class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        int index = 0;
        if(k > 0){
            for(int i = 0;i < n;i++){
                for(int j = 1;j <= k;j++){
                    index = (i + j) % n;
                    ans[i] += code[index];
                }
            }
        }
        else if(k < 0){
            for(int i = 0;i < n;i++){
                for(int j = 1;j <= abs(k);j++){
                    index = (i - j + n) % n;
                    ans[i] += code[index];
                }
            }
        }
        else{
            ans.resize(n);
        }
        return ans;
    }
};