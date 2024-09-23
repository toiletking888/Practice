class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        for(int i = 1;i <= 10000;i++){
            missing.push_back(i);
        }
        for(int i = 0;i < arr.size();i++){
            for(int j = 0;j < missing.size();j++){
                if(arr[i] == missing[j]){
                    missing.erase(missing.begin() + j);
                }
            }
        }
        return missing[k-1];
    }
};

// top solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;

        while(s<e){
        int mid= s+(e-s)/2;
        if(arr[mid]-mid-1<k){
            s=mid+1;
        }
        else{
            e=mid;
        }
        }
        if(arr[s]-s-1<k){
            return s+k+1;
        }
        return s+k;
    }
};