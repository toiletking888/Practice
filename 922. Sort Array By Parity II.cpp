class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        stack<int> odd;
        stack<int> even;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] % 2 == 0){
                even.push(nums[i]);
            }
            else{
                odd.push(nums[i]);
            }
        }
        for(int i = 0;i < nums.size();i++){
            if(i % 2 == 0){
                ans.push_back(even.top());
                even.pop();
            }
            else{
                ans.push_back(odd.top());
                odd.pop();
            }
        }
        return ans;
    }
};

// top solution
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i=0; //i will keep track of even place
        int j = 1; //j will keep track of odd place
        while(i<n && j<n){
            if(nums[i]%2==0) i+=2; //No need to change(i.e already in even place)
            else if(nums[j]%2==1) j+=2;//No need to change(i.e already in odd place)
            else swap(nums[i],nums[j]); 
            /* Swapping will occur when either of the two conditions is met:-
           1. The element nums[i] will be in an odd position, and it will wait until 
            nums[j] is found at an even position.

           2. The element nums[j] will be in an even position, and it will wait until 
            nums[i] is found at an odd position.
            */
        }
        return nums;
    }
};