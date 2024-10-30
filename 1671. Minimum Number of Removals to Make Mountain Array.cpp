class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int max_length = 0;
        vector<int> LIS(nums.size(), 1);
        vector<int> LDS(nums.size(), 1);
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }
        for(int i = n-1;i >= 0;i--){
            for(int j = n-1; j>i;j--){
                if(nums[j] < nums[i]){
                    LDS[i] = max(LDS[i], LDS[j]+1);
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(LIS[i] > 1 && LDS[i] > 1){
                max_length = max(max_length, LIS[i]+LDS[i]-1);
            }
        }
        return (n - max_length);
    }
};