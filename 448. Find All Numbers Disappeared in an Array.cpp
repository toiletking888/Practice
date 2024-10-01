class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> count;
        count.resize(nums.size()+1);
        for(int i = 0;i < nums.size();i++){
            count[nums[i]]++;
        }
        for(int i = 1;i < count.size();i++){
            if(count[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//top solution
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        
        vector<int> ans;
        int n=a.size();
        int mask=(1<<30)-1;
        for(int i=0;i<n;i++)
        {
            int x=a[i]&mask;
            int j=x-1;
            a[j]=a[j]|(1<<30);
            
        }
        for(int i=0;i<n;i++)
        {
            if(((a[i]>>30)&1)==0)
             ans.push_back(i+1);
        }

        return ans;
    }
};