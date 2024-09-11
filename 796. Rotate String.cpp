// use standard library string substr() method to compare the prefix of goal and postfix of string s
class Solution {
public:
    bool rotateString(string s, string goal) {
        int x = 0;
        int n = s.length();
        if(s.length() != goal.length()){
            return false;
        }
        else{
            while(x < n){
                if(s.substr(x, n-x) == goal.substr(0,n-x)){
                    break;
                }
                else{
                    x++;
                }
            }
            if(s.substr(0, x) == goal.substr(n-x,x)){
                return true;
            }
            else{
                return false;
            }
        }
    }
};