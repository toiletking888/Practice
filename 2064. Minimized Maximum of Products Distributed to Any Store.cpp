class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        sort(quantities.begin(), quantities.end());
        int ans = quantities.back();
        int l = 1, r = quantities.back();
        while(l <= r){
            int mid = (l+r)/2;
            int x = n;
            vector<int> store = quantities;
            int curr_store = 0, i = 0;
            while(i < m){
                store[i] -= mid;
                curr_store++;
                if(store[i] <= 0){
                    i++;
                }
            }
            if(curr_store <= n){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};