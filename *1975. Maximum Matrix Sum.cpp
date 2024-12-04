class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int negCount = 0;
        int minAbs = 999999;
        for(auto& v : matrix){
            for(int i : v){
                minAbs = min(minAbs, abs(i));
                if(i < 0){
                    ans -= i;
                    negCount++;
                }
                else{
                    ans += i;
                }
            }
        }
        if(negCount % 2 == 0){
            return ans;
        }
        else{
            return ans-(2*minAbs);
        }
    }
};