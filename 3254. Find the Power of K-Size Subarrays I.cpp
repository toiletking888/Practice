class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int check = 0;
        int temp_max = 0;
        if(k == 1){
            return nums;
        }
        else{
            for(int i = 0;i <= nums.size()-k;i++){
                for(int j = i;j < i+k-1;j++){
                    if(nums[j+1]-nums[j] == 1){
                        check++;
                    }
                    if(check == (k-1)){
                        temp_max = nums[j+1];
                    }
                }
                if(check == (k-1)){
                    ans.push_back(temp_max);
                }
                else{
                    ans.push_back(-1);
                }
                temp_max = 0;
                check = 0;
            }
        }
        return ans;
    }
};