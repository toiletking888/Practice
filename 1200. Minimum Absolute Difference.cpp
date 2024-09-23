// sort the original vector, calculate the difference list, find the minmum difference value, then retrun the twin value of minmum difference
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int> > ans;
        vector<int> set;
        vector<int> difference_order;
        int temp = 0;
        int min_difference = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0;i < arr.size()-1;i++){
            temp = arr[i+1] - arr[i];
            difference_order.push_back(temp);
        }
        min_difference = find_min(difference_order);
        for(int i = 0;i < difference_order.size();i++){
            if(min_difference == difference_order[i]){
                set.push_back(arr[i]);
                set.push_back(arr[i+1]);
                ans.push_back(set);
                set.clear();
            }
        }
        return ans;
    }
    int find_min(vector<int> vec){
        int min = 99999;
        for(int i = 0;i < vec.size();i++){
            if(vec[i]<min){
                min = vec[i];
            }
        }
        return min;
    }
};

// top solution
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        vector<vector<int>>v;
        int min_diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
            int diff=arr[i+1]-arr[i];
            if(diff<min_diff)
                min_diff=diff;
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]-arr[i]==min_diff)
                v.push_back({arr[i],arr[i+1]});
        }
        return v;
    }
};