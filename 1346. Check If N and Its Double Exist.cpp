class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0;i < arr.size();i++){
            if(arr[i] % 2 != 0){
                continue;
            }
            for(int j = 0;j < arr.size();j++){
                if((j!=i) && (arr[j] * 2 == arr[i])){
                    return true;
                }
            }
        }
        return false;
    }
};