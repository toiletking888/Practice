class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        while(i < n || j < n){
            while(start[i] == '_'){
                i++;
            }
            while(target[j] == '_'){
                j++;
            }
            if(start[i] != target[j]){
                return false;
            }
            if(start[i] == target[j] && start[i] == 'L'){
                if(i < j){
                    return false;
                }
            }
            if(start[i] == target[j] && start[i] == 'R'){
                if(i > j){
                    return false;
                }
            }
            i++;
            j++;
        }
        if(i == j){
            return true;
        }
        else{
            return false;
        }
    }
};
//top
