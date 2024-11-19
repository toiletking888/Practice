class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long temp = 0;
        unordered_set<int> seen;
        int startIndex = 0;
        for(int i = 0;i <= nums.size()-k;i++){
            for(int j = i;j < i+k;j++){
                if(seen.find(nums[j]) == seen.end()){
                    temp += nums[j];
                    seen.insert(nums[j]);
                }
                else{
                    i = j-1;
                    temp = 0;
                    break;
                }
            }
            ans = max(temp, ans);
            temp = 0;
            seen.clear();
        }
        return ans;
    }
};
//top solution
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long curr_sum = 0;
        unordered_map<int, int> count;
        int l = 0;
        for(int r = 0;r < nums.size();r++){
            curr_sum += nums[r];
            count[nums[r]]++;
            if(r-l+1 > k){
                count[nums[l]]--;
                if(count[nums[l]] == 0){
                    count.erase(nums[l]);
                }
                curr_sum -= nums[l];
                l++;
            }
            if(count.size() == k && (r - l + 1) == k){
                ans = max(ans, curr_sum);
            }
        }
        return ans;
    }
};