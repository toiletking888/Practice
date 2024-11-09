class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> X(x), N(n-1), ans = 0;
        int j = 0;
        for(int i = 0;i < 56;i++){
            if(X[i]){
                ans[i] = 1;
            }
            else{
                ans[i] = N[j++];
            }
        }
        return ans.to_ullong();
    }
};