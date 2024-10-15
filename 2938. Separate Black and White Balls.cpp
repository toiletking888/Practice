// since meeting a white ball, every black ball has to swap 
class Solution {
public:
    long long minimumSteps(string s) {
        long long times = 0, black = 0;
        for(int c : s){
            if(c == '1'){
                black++;
            }
            else{
                times += black;
            }
        }
        return times;
    }
};